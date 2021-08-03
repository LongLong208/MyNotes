# QT C++笔记

## 目录

[TOC]



## 1. 简介

GUI、套接字、进程……

通过实例学习



+ 对象 = 算法 + 数据结构

  程序 = 对象 + 对象间通信

  qt对象间通信：事件驱动信号槽机制

+ ui文件生成代码参考

+ qt帮助系统：文档、范例



![image-20210213221610589](https://i.loli.net/2021/03/03/JD68XztsKa4Lmq3.png)



#### Qt程序运行原理

![image-20210214001717433](https://i.loli.net/2021/03/03/U5DvfhOnVizYPWo.png)



#### 项目文件 .pro

```
QT += core gui  # 包含了core和gui库
TARGET = 【目标文件名】
TEMPLATE = app # app表示编译成可执行程序
CONFIG += c++11  # c++11标准
```

![image-20210213233332985](https://i.loli.net/2021/03/06/gGKU68HbpTu74lX.png)



#### main.cpp

```c++
#include "first.h"

#include <QApplication>

// 应用程序入口
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);    // a对象管理时间循环
    First w;    // 窗体类
    w.show();    // 显示窗口

    //调用事件管理对象的成员函数：事件循环
    return a.exec();
}

/*
qt程序：时间驱动，信号槽机制
int QApplication::exec()
{
    while(1)
    {
        1.等待事件发生（阻塞）
        2.事件函数调用（虚函数：实质是回调）
            A、标准事件（Qt库的类【基类】的虚函数，都已实现，不适合可重写）
            B、非标准事件
                触发一个信号，调用用户关联的一个由用户定制的特殊函数【槽函数】
    }
}
*/

```

####  项目名.h

```C++
#ifndef FIRST_H
#define FIRST_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui
{
//前向声明一个类
//ui文件"first.ui"
//在编译时被uic.exe
//自动转换生成的在影子目录下的ui\first.h中
    class First;
}
QT_END_NAMESPACE

class First : public QWidget
{
    // 元对象系统的宏
    // 元对象系统就是支持信号槽
    // 只要是要支持信号槽则必须使用这个宏
    Q_OBJECT

public:
    First(QWidget *parent = nullptr);
    ~First();


private slots:
    // 槽函数：关联信号，表示该信号触发该函数，自动被main的事件回调
    // 命名规则：on_对象名_信号名(参数列表);
    void on_pushButton_clicked();

private:
    // 定义Ui名字空间的MyWnd的指针
    // 用于组装窗口工作区
    Ui::First *ui;
};
#endif // FIRST_H

```

#### ui\项目名.h

通过编辑界面并对照影子目录下的 ui\项目名.h 文件，即可快速了解组件的使用方法



![image-20210214005306527](https://i.loli.net/2021/03/06/fbmsQOHpIjV8lvL.png)



#### Resources文件

![image-20210214221133449](https://i.loli.net/2021/03/06/cz54D8wispR7E6W.png)

![image-20210214221233529](https://i.loli.net/2021/03/06/x8rZsFk2V3UvAjQ.png)

* 资源文件在编译时就会作为数据存储在内存中，所以不能添加过大的资源文件

* 从资源文件中读资源时，路径以 “ : ” 开头

  如：":/pic/1.png"



#### 打印跟踪

```C++
qDebug("Items in list: %d", myList.size());

// if you include <QtDebug>
qDebug() << "Brush:" << myQBrush << "Other value:" << i;
```



#### 注意

查询某个类属于的库

![image-20210213232715845](https://i.loli.net/2021/03/06/w3oCKkyafMmqeBL.png)



![image-20210213234547748](https://i.loli.net/2021/03/06/2EMvowtSnipbsxz.png)





QWidget 对象的构造函数的参数是一个父对象，表示该对象放入了父对象中

```c++
QPushButton *btn = new QPushButton(MyWnd);
// btn按钮放入了MyWnd中
```

从 QObject 派生的对象，只要指定了父对象，就会被自动回收，无需delete





## 2. 信号和槽



* 信号的形式上像函数，但其实不是函数

* 槽的本质就是成员函数

* 信号槽机制实质就是信号将参数传递给槽函数（通讯），或不传参只调用（通知）

* 而信号和槽，需要进行连接（自定义信号需要手动连接）



#### 手动绑定信号与槽函数

选择该选项后，连线连接两个Qwidget对象

或者在下方的栏目中按加号添加

![image-20210214202642581](https://i.loli.net/2021/03/03/c3Ldfk74MlGZjPB.png)



#### 自定义信号和槽

```c++
// 项目名.h
class xxx : public Qwidget
{
    ...
        
signals:
    /* 自定义一个信号
     * 这里的参数是用来传递给槽函数的
     * 触发该信号时，其中的参数就被传递给了槽函数
     * 自定义的信号必须手动连接槽函数
     * 
     * 1.有声明无实现
     * 2.返回值为void
     * 3.可带参、可重载
     **/
    void sig(参数表);  
    
    ...
        
private/public/protect slots:
    /* 自定义一个信号槽，这里只给出声明
     * 自定义槽：
     * 1.有声明有实现
     * 2.返回值为void
     * 3.可带参、可重载
     **/
    void slotGetSig(参数表);
    
    ...
}

```



#### 连接函数

```C++
%"函数原型:  
% QMetaObject::Connection QObject::connect(
    const QObject * sender,
    const char * signal,
    const QObject * receiver,
    const char * method,
    Qt::ConnectionType type = Qt::AutoConnection
);

/*
 * 一个信号可以与一个或多个槽函数连接
 * 一个信号可以与一个或多个信号连接
 * 一个槽也可以与一个或多个信号连接
 *
 * 信号的参数可以多于等于槽的参数，但不能小于
 *
 * 写法一：
 * 	参数signal 需要使用宏 SIGNAL() 修饰
 * 	参数method 需要使用宏 SIGNAL() 或 SLOT() 修饰
 *
 * 如：信号是sig(int),则写法是：SIGNAL(sig(int))
 * 		SIGNAL(信号名(参数,...))
 * 		SLOT(信号名(参数,...))
 *		不写形参名
 *
 * 写法二：
 * 		如：
 *			&QPushButton::pressed
 *
 *
 * 用法：
 *	connect(被观察者,信号,观察者,函数);
 *	connect(被观察者,信号,观察者,信号);
 * 	connect(被观察者,信号,函数);
 *
 *
 * 断开连接函数：disconnect()
 **/
```



#### 参数对应关系

![image-20210214210426258](https://i.loli.net/2021/03/06/L7CJi8byVAOoU9H.png)



#### 程序触发信号（emit）

```c++
// signal一般是在事件处理时Qt发出，如果需要程序触发信号，则使用emit
// 貌似新版(Qt5+)不需要emit

// 语法：
void func()
{
    ...
	emit 信号名(参数);
	...
}
```



#### 信号和槽的重载

```C++
class A{
	...
      
signal:
    void ASignal();
    void ASignal(int);
    
public slots:
    void ASlots();
    void ASlots(int);
    
	...
};

// 信号连接时，需使用信号指针和槽指针，实例如下：
void (A::*signalPtr)(int) = &A::ASignal;		// 信号指针
void (A::*slotsPtr)(int) = &A::ASlots;			// 槽指针
connect(a,signalPtr,a,slotsPtr);
```











## 3.常用的类

![image-20210214222405843](https://i.loli.net/2021/03/06/5jVt6eY34lakiFf.png)

![image-20210214222456092](https://i.loli.net/2021/03/06/4utj6ke3hPJXnS5.png)

![image-20210214222538601](https://i.loli.net/2021/03/06/N2PL9siM7bla4nF.png)![image-20210214222623712](https://i.loli.net/2021/03/06/5jVt6eY34lakiFf.png)





#### 窗口五大部件 

![image-20210306164351227](https://i.loli.net/2021/03/06/BDiPR1tckUhWmGb.png)

```C++
setWindowTitle(QString*)

// MenuBar
QMenuBar* menuBar = new QMenuBar(this);	 // 菜单栏
QMenu* menu = menuBar->addMenu("文件");  // 菜单
QAction* act = menu->addAction("打开");  // 子项

    menuBar->addMenu("编辑");
    menuBar->addMenu("构建"); 


// Tool Bar
QToolBar* toolBar = new QToolBar(this);
// this->addToolBar(Qt::LeftToolBarArea,toolBar);  // 可s设置默认停靠范围
	toolBar->addAction("新建");
	toolBar->addSeparator();  // 添加分割线
	toolBar->addAction("保存");
	toolBar->setAllowedAreas(Qt::LeftToolBarArea | Qt::BottomToolBarArea);  // 设置允许停靠区域
		/* Qt::LeftToolBarArea 
		 * Qt::BottomToolBarArea 
		 * Qt::RightToolBarArea 
`		 * Qt::TopToolBarArea
		 * Qt::AllToolBarAreas
		 * Qt::NoToolBarArea
		 **/


// StatusBar
QStatusBar* statusbar =  new QStatusBar(this);
	status->addWidget(new QLabel("Ping: 2036ms"));  // addWidget(QWidget*)
	status->addPermanentWidget(new QLabel("Hello"));	// 添加在右边


// Central Widget
this->setCentralWidget(new QTextEdit("中心部件"));  // setCentralWidget(QWidget*)


// Dock Widget
QDockWidget* dock = new QDockWidget("文本1");
this->addDockWidget(Qt::LeftDockWidgetArea,dock);
```





#### QDialog 对话框

![image-20210214223029220](https://i.loli.net/2021/03/06/R1iKmxWtn2apv5M.png)



##### 对话框使用样例

```C++
/* !
 * 模态对话框：对话框执行完之前无法操作其他窗口
 * 非模态对话框：对照模态对话框,,
 **/
    
// 模态对话框的使用 不要调用show()
	dialog->exec();

// 非模态对话框的使用
	dialog->show();

// 在函数中两种使用变量方法：
// 方法一：使用new，函数返回时不会自动释放，需要使用如下函数
	QDialog* dialog = new QDialog(this);
	dialog->setAttribute(Qt::WA_DeleteOnClose);	// 关闭时释放对话框

// 方法二：使用局部变量，函数返回时自动释放
	QDialog dialog(this);
        

###// 文件对话框
QFileDialog f;					   // 定义文件对话框
f.setWindowTitle("设置对话框标题");
QString path = QDir::currentPath();  // 获取当前路径
f.setDirectory(path);
QStringList list;
list << "所有文件(*.*)"
     << "文本文件(*.txt)"
     << "C/C++(*.c *.cpp)"
     << "头文件(*.h)";
    f.setNameFilters(list);			// 设置文件过滤器

// f.exec() 调用文件对话框的事件循环
// 判断对话框的执行结果
if(f.exec() == QDialog::Accepted)
{
    // 获取选择的文件的文件名列表
    QStringList fileList = f.selectedFiles();
    ...
} else {
    ...
}

//也可使用静态成员函数，具体可看帮助文档
%"函数原型:  
% QString QFileDialog::getOpenFileName(...)
% QStringList QFileDialog::getOpenFileNames(...)
    

###// 颜色对话框
QColor color = QColorDialog::getColor(Qt::blue,this,"文字颜色"); //QColor getColor(默认颜色,窗口父对象,对话框标题);


###// 文字对话框
%"函数原型:  
% QFont QFontDialog::getFont(bool *ok,字体,窗口父对象,对话框标题);

// examles:
bool ok;
QFont font = QFontDialog::getFont(&ok, QFont("Times", 12), this);
if (ok) {
	// font is set to the font the user selected
} else {
	// the user canceled the dialog;
    // font is set to the initial value, in this case Times,12.
}


###// 消息对话框
%"函数原型:   
% QMessageBox::critical(this,"错误","错误了！");
% QMessageBox::warning(this,"警告","警告了！");
% QMessageBox::information(this,"提示","提示你！");
% QMessageBox::question(this,"问题","你确定吗？");

// StandardButton QMessageBox::critical(窗口父对象,标题,窗口内文本,StandardButton,默认选择按钮)  StandardButton是一个枚举
```





#### QLabel 文本框

```c++
### QLabel
QLabel* label = new QLabel;
label->setParent(this);
label->move(0,100);
label->setText("今天天气如何？");
label->setFont(QFont("楷体",20,10,1));  // QFont(...) 匿名字体对象
```





#### QSlider 滑动条

```c++
### QSlider
QSlider* slider = new QSlider;
slider->setParent(this);
slider->move(300,100);
slider->setValue(0);
slider->setMaximum(100);	// 滑动条默认取值是0~99，设置最大值为100后取值为0~100
// 通过滑动滑动条改变字体大小
connect(silder,&QSlider::valueChanged,[label](int _value){
   label->setFont(QFont("楷体",_value,10,1)); 
});
```





#### QTreeWidget 树形组件

QTableWidget类似

```c++
QTreeWidget* treeWidget = new QTreeWidget(this);
treeWidget->setHeaderLabels(QStringList()<<"名称"<<"类型"<<"详细介绍");     // 设置表头
QTreeWidgetItem* item = new QTreeWidgetItem(QStringList()<<"A"<<"A"<<"A");
treeWidget->addTopLevelItem(item);		// 添加顶级表项
item->addchild(new QTreeWidgetItem(QStringList()<<"A1"<<"A1"<<"A1"))	// 添加子项
```





#### QString 字符串

```C++
%"函数原型:  
% bool contains(char) 				  	 // 查询字符串中是否含有某字符
% void chop(int n)					 	// 从尾部删除n个字符
% QByteArray toUtf8()						// 转为QByteArray
% static QString number(int/double/...)  	  // 数值变量转字符串
```





#### QPoint 向量 点

```C++
// QPoint 实际上是一个向量
QPoint a(0,3);
QPoint b(3,0);
QPoint c = a + b;	// c = (3,3)

// 判断一个点是否在某个控件内
bool QWidget::geometry().contains(QPoint p)
```

##### 向量运算复习

$\vec{OA} + \vec{OB} = (x1 + x2, y1 + y2)$
$n \cdot \vec{OA} = (n \cdot x, n \cdot y)$



点乘，结果是一个标量
    $\vec{OA} \cdot \vec{OB} = |OA| * |OB| * cos<\vec{OA},\vec{OB}> = x1 * x2 + y1 * y2$



叉乘，结果是一个向量，大小如下，方向是四指由OA弯曲向OB时拇指的方向（右手定则）

   $\vec{OA} \times \vec{OB} = |\vec{OA}| * |\vec{OB}| * sin<\vec{OA},\vec{OB}>$







#### QFile QDataStream 文件和数据流

```c++
// 文件对象
QFile file(QString("filename"));
if(!file.open(QIODevice::ReadOnly))
    return;
while(!file.atEnd())
{
    ...
    char str[1024];
    file.readLine(str,sizeof str);	// str装读入的数据，并传入str的大小，每次最多只能读入sizeof str的数据
    ...
    // 另一版本
    QByteArray arr;
    arr += file.readLine();
    ...
    // 读取全部
    file.readAll();
    ...
}
file.close();

// 数据流对象，以二进制读取、保存文件
QDataStream fout(&file);
fout << "abcde" << 12345;
```





#### QSettings 配置文件对象

```C++
QSettings settings(文件路径);
setting.setValue("volume",50);	// 设置volume数值
setting.value("volume");	    // 读取volume数值
```



#### QPainter QPainterPath 画图类

```C++
// QPainter 使用示例
void ExampleWidget::paintEvent(QPaintEvent* event)
{
    QPainter* painter = new QPainter(this);
    painter->begin(this);    //画家要开始画画了，设置画图设备（画布）为this

    QPen pen(QColor(255,0,0));   //红色画笔
    pen1.setWidth(3);             //画笔宽度为3
    painter->setPen(pen);        //设置画笔
    painter->setBrush(QBrush(QColor(98,66,227)));  //设置画刷

    painter->drawLine(0,0,100,100);		// 两点一线
    painter->end();				// 结束
}
 

// QPainter 其他画图函数
%"函数原型:   
% QPainter::drawImage(绘制矩形大小，图片，图片部分截取)
% QPainter::drawLine(起点,终点)
% QPainter::drawRect(QRect(起点，终点))
% QPainter::drawEllipse(QRect(起点，终点))
% QPainter::drawPolygon(点数组,点数)
% QPainter::drawText(起点,"字")

// 利用QPainterPath类可以实现QPainter类的draw()函数能够实现的所有图形
// 例如，对于QPainter::drawRect()函数，除了可用上面介绍的QPainterPath::addRect()的方式实现外，还可以用如下方式实现：
QPainterPath path;
path.moveTo(0,0);
path.lineTo(200,0);
path.lineTo(200,100);
path.lineTo(0,100);
path.lineTo(0,0);
// 调用 drawPath()来画以上的线段
QPainter::drawPath(path);
// 这是一个更通用的方法，其他（如多边形等）图形都能够使用这种方式实现。
```







#### 样式表（类CSS）

```C++
QPushButton* btn = new QPushButton(this);
btn->setStyleSheet(
    "QPushButton:hover {background-color:rgb(00,00,00)}"	// 鼠标悬浮时的样式
);
```





## 4.事件

#### 键盘鼠标事件

```C++
// 都是QWidget中定义的虚函数，使用时直接重写即可，当事件发生时，对应函数会自动被调用
%"函数原型:  
% virtual void QWidget::keyPressEvent(QKeyEvent* event)
% virtual void keyReleaseEvent(QKeyEvent*)

% virtual void mouseDoubleClickEvent(QMouseEvent*)
% virtual void mousePressEvent(QMouseEvent*)
% virtual void mouseReleaseEvent(QMouseEvent*)
% virtual void mouseMoveEvent(QMouseEvent*)

% virtual void leaveEvent(QEvent*)	// 鼠标离开
% virtual void enterEvent(QEvent*)	// 鼠标进入 

% virtual void wheelEvent(QWheelEvent*)	// 鼠标滚轮滚动


// QMouseEvent
int QMouseEvent::button()		// 返回按下的鼠标键
QPoint QMouseEvent::pos()			// 窗体中的位置
QPoint QMouseEvent::globalPos()	// 整个屏幕中的位置
    
//mouseMoveEvent中，默认鼠标左键按下后移动才能触发，不过设置了setMouseTracking(true)后不需要按左键再移动就能检测
QWidget::setMouseTracking(bool)
    
    
// QKeyEvent
int QKeyEvent::key()		    // 返回按下的按键
    Qt::Key_W, Qt::Key_S, ...	// 可以使用此枚举判断按下的键
```



#### 定时器

```C++
// 老式定时器用法
%"函数原型:   
// 定时器更新函数
% virtual void QObject::timerEvent(QTimerEvent* event)  
  
% int QObject::startTimer(int time)
% int QTimerEvent::timerId()
    /* 开启一个定时器，返回一个用于区别不同定时器的id
     * 定时器id用法：与QTimerEvent的定时器id对照，来判断是否是同一个定时器
     * 在一个QObject中调用了startTimer后，将隔time毫秒调用一次QObject::timerEvent
     **/
    
// 示例
void timerEvent(QTimerEvent* event)
{
    if(timerID1 == event->timerId())//定时器1 判断
    {
//        处理逻辑1

    }
    if(timerID2 == event->timerId())
    {
//       处理逻辑2
    }
}
    


// 定时器用法二
QTimer *timer = new QTimer(this);  // 创建定时器对象
timer->start(time);  // 开始定时器
timer->stop();		// 停止定时器
// 绑定QTimer::timeout()信号，每隔time毫秒将自动发射一次QTimer::timeout()信号
connect(..., &QTimer::timeout, ......);
```



## 5. 实例：飞机大战



窗口有多个视图，视图可以设置场景，场景可以添加多个图片元素



##### 一. 视图常用类

|          类名          |              作用               |
| :--------------------: | :-----------------------------: |
|     QGraphicsView      | 图形显示视图类 （用于显示场景） |
|     QGraphicsScene     |              场景               |
|     QGraphicsItem      |              元素               |
|   QGraphicsLineItem    |             线元素              |
|  QGraphicsPixmapItem   |   像素图元素（不同平台可用）    |
|   QGraphicsTextItem    |            文本元素             |
| QGraphicsItemAnimation |            动画元素             |



##### 二. 场景的显示

> 1. 创建窗口程序
> 2. 在窗口类中添加 <视图类对象> 和 <场景类对象>
> 3. 设置 <视图类对象> 的渲染场景为对应的 <场景类对象>
> 4. 创建一个文本、图片或线条添加到场景中并设置位置



##### 示例

```C++
// QGraphicsItem的派生类 不支持 Q_OBJECT（老式 信号和槽 宏）

/****** 声明 ******/
QGraphicsView mGameView;			//游戏视图
QGraphicsScene mScene;				//游戏场景
QGraphicsPixmapItem mBackGround1;	//场景元素（背景）
QGraphicsPixmapItem mBackGround2;
QGraphicsPixmapItem mPlane;		// 场景元素（飞机）

/****** 使用 ******/
mGameView.setSceneRect(QRect(0,0,512,768));
mScene.setSceneRect(QRect(0,0,512,768));
// 设置场景元素的属性（图片、坐标等）
mBackGround1.setPixmap(QPixmap("filepath"));
mPlane.setPixmap(QPixmap("filepath"));

%"函数原型:  
% QGraphicsPixmapItem::setPos(int x, int y)
% QGraphicsPixmapItem::setX(int x)
% QGraphicsPixmapItem::setY(int y)

// 添加图片元素到场景
mScene.addItem(&mBackGround1);
mScene.addItem(&mBackGround2);
mScene.addItem(&mPlane);
mScene.addWidget(...);	// 可以添加很多其他的
// 设置视图的场景
mGameView.setScene(&mScene);
//设置视图的父亲
mGameView.setParent(this);
mGameView.show();

### 背景滚动
	/* 原理：
	 * 背景图片的上下是连贯的
	 * 设置两个场景元素用于设置背景
	 * 将两个背景依靠设置坐标函数来上下拼接起来，并随定时器事件而滚动
	 * 当背景1滚动到窗口外后，将其拼接在背景2的上方
	 **/
QTimer timer = new QTimer(this);
QTimer.start(100);
connect(timer, &QTimer::timeout, this, &Widget::BGMove);
    
void BGMove(){
    mBackGround1.moveBy(0,2);
    mBackGround2.moveBy(0,2);
}
```



##### 三. 音乐 QMediaPlayer

```c++
// 项目文件
QT += multimedia

    
%"函数原型: 
% QMediaPlayer::setMedia(QUrl(%url))	// 设置音乐
  % url = "qrc:/" + 前缀名 + 路径
% QMediaPlayer::play()	// 播放音乐
```



##### 四. 对象池、继承链

![image-20210409001155980](https://i.loli.net/2021/04/09/qKTPRciyzB3aOH7.png) 

###### 对象池：享元模式

![image-20210412233641086](https://i.loli.net/2021/04/12/9bhdxrNcj1MlDfg.png)



## 6. Xml

示例代码

```C++
#include "Widget.h"
#include "ui_widget.h"
#include <QtXML>
#include "Hero.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->textEdit->setReadOnly(true);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_LoadBtn_clicked()
{
    //构建文件对象 QFile
    QFile file("HeroInfo.xml");
    if(!file.open(QIODevice::ReadOnly))//打开文件用于读取
        return;

    //**************XML文件读取*************
    QDomDocument doc;//创建文档对象
    doc.setContent(&file);//设置文档内容
//    doc.setContent(file.readAll());//设置文档内容

    QDomElement root = doc.firstChildElement("Root");//获取第一个子标签
    QDomElement hero = root.firstChildElement("Hero");//获取hero子标签

    QString text;
    while (!hero.isNull())//判断hero标签是否存在
    {
        text += "Name:" + hero.attribute("name");//读取属性
        text += "  Atk:" + hero.attribute("atk");
        text += "  Def:" + hero.attribute("def");
        text += "  HP:" + hero.attribute("hp");

        //读取标签内容
        text += "  Des:" + hero.text()+"\n";

        hero = hero.nextSiblingElement("Hero");//获取下一个Hero兄弟标签
    }
    ui->textEdit->setText(text);

    file.close();
}

void Widget::on_SaveBtn_clicked()
{
    QVector<Hero> vec;
    vec.push_back(Hero("曹操",100,25,2000,"曹孟德"));
    vec.push_back(Hero("曹丕",100,25,2000,"曹子桓"));
    vec.push_back(Hero("曹植",100,25,2000,"曹子建"));
    vec.push_back(Hero("曹彰",100,25,2000,"曹xx"));
    vec.push_back(Hero("曹真",100,25,2000,"曹xx"));

    //创建xml文档对象
    QDomDocument doc;
    QDomElement root = doc.createElement("Root");//创建root标签

    for(int i =0;i < vec.count();i++)
    {
        QDomElement hero = doc.createElement("Hero");//创建hero标签
        root.appendChild(hero);

        hero.setAttribute("Name",vec[i].mName);//设置属性 Name
        hero.setAttribute("Atk",vec[i].mAtk);
        hero.setAttribute("Def",vec[i].mDef);
        hero.setAttribute("HP",vec[i].mHp);

        QDomText text = doc.createTextNode(vec[i].mDescript);
        hero.appendChild(text);
    }
    doc.appendChild(root);//将root节点添加到文档对象

    //创建文件对象
    QFile file("./Config.xml");
    if(!file.open(QIODevice::WriteOnly))
        return;

    QTextStream outStream(&file);//创建文本流对象
    doc.save(outStream,4);
    file.close();
}
```



## 7.TCP

```C++
// 项目文件
QT += network
    
// 类
QHostAddress
QHostInfo	// 主机信息
QTcpServer	// TCP服务器
QTcpSocket	// 套接字（连接主机）
    
%"函数原型
% QString QHostInfo::localHostName()  // 本地主机名

% bool QTcpServer::listen(QHostAddress &address = QHostAddress::Any, quint16 port = 0)	// 监听客户端连接（开启某个端口号服务）
% QTcpSocket QTcpServer::nextPendingConnection()  // 返回下一个即将连接的套接字

% bool QTcpSocket::connectToHost(QHostAddress &address/QString hostName, quint16 port, OpenMode mode = ReadWrite)  // 连接服务器
% ??? QTcpSocket::write(QByteArray message)  // 发送信息
% QByteArray QTcpSocket::read(qint64 maxlen) // 读取信息
    % qint64 QTcpSocket::read(char *data, qint64 maxlen)

%"信号
% QTcpSocket::connected  // 连接成功信号
% QTcpSocket::readyRead  // 准备读取新信息

% QTcpServer::newConnection  // 有客户端连接时触发
    
// 主机信息
QString hostName = QHostInfo::localHostName();
QHostInfo info;
info = QHostInfo::fromName(hostName);		// 通过主机名，返回主机信息对象
QList<QhostAddress> addressList = info.addresses();  // 返回主机ip地址	

```





## 8.UDP

```C++
// 项目文件
QT += network
    
//类
QHostAddress
QUdpSocket	// UDP套接字
QNetworkDatagram
    
%"信号
% QUdpSocket::readyRead		// 接收消息触发
    
%"函数原型
    QUdpSocket
    % writeDatagram(const QNetworkDatagram& datagram)	// 发信息
    % writeDatagram(QString data, qint64 len, const QHostAddress &host, quint64 port)
    % readDatagram(char *data, qint64 maxlen)	// 收信息
    % bool QUdpSocket::bind(const QHostAddress &address, quint16 port = 0) // 绑定本应用程序端口
    % bool QUdpSocket::bind(quint16 port)
        % bind(port, QAbstractSocket::ShareAddress)  // 可接收自己消息
    % bool joinMulticastGroup(const QHostAddress &groupAddress)  // 加入组播组 注意：用户可用组播ip地址：224.0.2.0 ~ 238.255.255.255
    % bool hasPendingDatagrams()  // 判断是否接收到数据报
```



课件

```C++
一、单播
1、创建套接字            socket = new QUdpSocket();
2、绑定端口号            socket->bind(8888);   //返回值bool，判断是否绑定成功
     PS：这个是用来接受数据的，如果只是发送数据，则不需要绑定端口号
3、发送数据
     socket->writeDatagram(ui->textEdit->toText().toUtf8(),QHostAddress("192.168.137.1"),6677);
     参数1：要发送的消息     参数2：接收者的ip地址   参数3：接受者的端口号
4、读取数据
     connect(socket,SIGNAL(readyRead()), this,SLOT(readMsg()));
     当有消息传入时，触发 readyRead 信号，调用自定义的槽函数 readMsg()



PS：在同一台计算机上运行时，两个运行程序需要绑定不同的端口
       如果在不同计算机上运行，可以使用相同的端口，因为IP地址不同了，不会导致绑定时发生冲突。
	   一般的UDP通信程序都是在不同的计算机上运行的，约定一个固定的端口作为通信端口
	   



二、广播
     广播只有和单播相比，发消息时，只有接收端ip地址不同
     socket->writeDatagram(ui->textEdit->toPlainText().toUtf8(),QHostAddress::Broadcast,6677);
     PS：建议把端口号，代码直接写死（统一端口号）


三、组播
       采用UDP组播，必须使用一个组播地址，组播地址是D类IP地址，有特定的地址段。多播组可以是永久的，也可以是临时的。多播组地址中，有一部分由官方分配，称为永久多播组。永久多播组保持不变的是它的IP地址，组中的成员构成可以发生变化。永久多播组中成员的数量可以是任意的，甚至可以为零。那些没有保留下来的供永久多播组使用的IP组播地址，可以被临时多播组利用。关于组播IP地址，有如下约定：

       socket->bind(QHostAddress::AnyIPv4,5566,QUdpSocket::ShareAddress);   //绑定，使用统一端口
       joinMulticastGroup( 组播ip地址 )       //使主机加入一个多播组 （组播地址，可以理解为qq群号）
       leaveMulticastGroup( 组播ip地址 )    //使主机离开一个多播组
       socket->writeDatagram(text.toUtf8(), 组播ip, 5566);  //发送消息，第二个参数填组播地址
       收消息功能与单播UDP完全相同（注意组播地址范围！）239.0.0.0 -- 239.255.255.255

```



## 9.SQL

```c++
	QSqlQuery query;
     query.prepare("INSERT INTO person (id, forename, surname) "
                   "VALUES (:id, :forename, :surname)");
     query.bindValue(":id", 1001);
     query.bindValue(":forename", "Bart");
     query.bindValue(":surname", "Simpson");
     query.exec();



 QSqlQuery q("select * from employees");
 QSqlRecord rec = q.record();

 qDebug() << "Number of columns: " << rec.count();

 int nameCol = rec.indexOf("name"); // index of the field "name"
 while (q.next())
     qDebug() << q.value(nameCol).toString(); // output all names
```

