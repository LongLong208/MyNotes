<!-- @import "/root.css" -->

# QML

<hr>

<br>

## QML 与 C++ 交互

[[1] qml function](#001)
[[2] cpp function](#002)
[[3] qml signal](#003)
[[4] cpp signal](#004)
[[5] cpp class](#005)
[[6] cpp 附加属性](#006)
[[7] 一些 cpp 与 qml 类型对照](#007)

### [1] qml function {#001}

main.cpp
```cpp
QQmlApplicationEngine engine;
auto root = engine.rootObjects();
auto target = root.first()->findChild<QObject*>("ObjectName")

QVariant ret;
QVariant param;
QMetaObject::invokeMethod(target, "getText", Q_RETURN_ARG(QVariant, ret), Q_ARG(QVariant, param));
```

qml
```qml
Window {
    Item {
        objectName: "ObjectName"
        function: getText(param) {
            // ...
        }
    }
}
```

<hr class=short>

### [2] cpp 对象注册 {#002}

Person.h
```cpp
class Person : public QObject
{
    Q_OBJECT

public:
    Q_INVOKABLE void print() const noexcept;
private:
    QString _name;
    quint32 _age;
};
```

main.cpp
```cpp
Person person();

//![1] 方法1：注册（以下是单例的示范）
qmlRegisterSingletonInstance("MyModule", 1, 0, "Person", &person);
//![1] 

//![2] 方法2：使用引擎注入到上下文（用得多）
auto context = engine.rootContext();
context->setContextProperty("myPerson", &person);
//![2]
```

qml
```qml
import MyModule 1.0

Window {
    // ...
    Button {
        onClicked: {
            //![1] 方法1
            Person.print()
            //![1]

            //![2] 方法2
            myPerson.print()
            //![2]
        }
    }
}
```

<hr class=short>

### [3] qml signal {#003}

Person.h
```cpp
class Person : public QObject
{
    Q_OBJECT

public slots:
    void clickDemo() const noexcept;
};
```

main.cpp
```cpp
Person person();

auto buttonQml = engine.rootObjects().first()->findChild<QObject*>("myButton");
QObject::connect(buttonQml, SIGNAL(clicked()), &person, SLOT(clickDemo()));
```

<hr class=short>

### [4] cpp signal {#004}

Person.h
```cpp
class Person : public QObject 
{
signals:
    void mySignal() const;
};
```

qml
```qml
Window {

    Connections {
        target: myPerson
        onMySignal() {
            //...
        }
    }
}
```

<hr class=short>

### [5] cpp class {#005}
```cpp
class MyType {
    Q_OBJECT
    Q_PROPERTY(QString name READ getName WRITE setName NOTIFY nameChanged)

public:
    void setName(QString name) const noexcept;
    QString name(QString name) const noexcept;

signals:
    void nameChanged(QString)

private:
    QString m_name;
}
```

main.cpp
```cpp
qmlRegisterType<MyType>("MyModule", 1, 0, "MyType");
// 注入方法二请查询宏： QML_ELEMENT
```

qml
```qml
Window {
    MyType {
        name: "example"
        onNameChanged: {
            console.log(name)
        }
    }
}
```

<hr class=short>

### [6] cpp 附加属性 {#006}

使用了 QML_ELEMENT 的注入方法

cpp
```cpp
class Info : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    QML_ANONYMOUS
public:
    Info(QObject* parent);
    QString name();
    void setName(QString name);
signals:
    void nameChanged();
private:
    QString m_name;
};

class Person : public QObject
{
    Q_OBJECT
    QML_ATTACHED(Info)
    QML_ELEMENT
public:
    Person(QObject* parent);
    static Info* qmlAttachedProperties(QObject* object)
    {
        return new Info(object);
    }
}
```

qml
```qml
Window {
    Button {
        Person.name: "Name"
        onClicked: {
            console.log(Person.name)
        }
    }
}
```

<hr class=short>

### [7] 一些 cpp 与 qml 类型对照 {#007}


|       cpp        |  qml  |    解释    |
| :--------------: | :---: | :--------: |
|    QQuickItem    | Item  | qml 基础项 |
| QQmlListProperty |  []   |  类js数组  |

<br>

QQmlListProperty 使用方法
```cpp
class MyClass {
    Q_PROPERTY(QQmlListProperty<MyType> typeList READ typeList)

public:
    QQmlListProperty<MyType> typeList() {
        return QQmlListProperty<MyType>(this, &m_typeList,
            &MyClass::append,
            &MyClass::count,
            &MyClass::at,
            &MyClass::clear,
            &MyClass::replace,
            &MyClass::removeLast
        )
    }

    // 自定义实现操作函数
    static void append(QQmlListProperty<MyType>* list, MyType *);
    static int count(QQmlListProperty<MyType>*);
    static MyType* at(QQmlListProperty<MyType>*, int index);
    static int clear(QQmlListProperty<MyType>*);
    static replace(QQmlListProperty<MyType>*, int index, MyType*);
    static removeLast(QQmlListProperty<MyType>*);

private:
    QList<MyType*> m_typeList;
};
```

qml
```qml
MyClass {
    typeList: [
        MyType {

        },
        MyType {

        },
        MyType {

        }
    ]
}
```

<hr>

<br>

## QML 动态加载组件

### Component

```qml
Component {
    id: myComponent

    // 在这里定义属性或对象，可以使用其他 qml 文件
    ...
    Label{} 
    Text{} 
    ...
}

Column {  // 使用 组件myComponent
    Component.onCompleted: {    // 任意函数或信号
        myComponent.createObject(this, {
            /* 额外属性 */
            text: "hello world"
        })
    }
}
```

<hr class=short>

### js 动态加载组件

js 函数
```js
/**
 * js 动态加载组件
 * @param {url} qml 文件的 url
 * @param {mode} 加载模式: 0 = Component.PreferSynchronous 同步加载（阻塞线程）; 1 = Component.Asynchronous 异步加载
 * @param {parent} 设置被加载的 qml 对象的父对象
 */
function create(url, mode, parent, properties)
{
    let component = Qt.createComponent(url, mode, parent)   // 返回一个组件
    if (component.status === Component.Ready)
    {
        component.createObject(parent, properties)  // 组件的加载
    }
}
```
