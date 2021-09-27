
## MPE 的 c++ 支持

建议先看完 `在 VSCode 中用 Markdown 做「数字化」学习笔记` 再看本教程

要想运行 c++ 代码段，需要完成以下配置

1. 首先需要 c++98 及以上编译环境

2. 配置环境变量。
    步骤：此电脑 → 属性 → 高级系统设置 → 环境变量 → 用户变量 新建
    填写目录为 run.exe 和 cppmd.bat 所在目录
    ![](https://i.loli.net/2021/08/23/TPF6dw4Q8bSHlg9.png)
    ![](https://i.loli.net/2021/08/23/N2oxBiArm8Mu1nC.png)
    ![](https://i.loli.net/2021/08/23/rD62CnaG5B7QJli.png)
    ![](https://i.loli.net/2021/08/23/Nmwa5x7JekI2dPC.png)
    ![](https://i.loli.net/2021/08/23/8Rti9SNa4FyEdAG.png)
    填写为这个目录
    例如我的是：`D:/1Notes/.mybat`
    ![](https://i.loli.net/2021/08/23/Uwdm5Z7rMxQKgC1.png)
    编辑用户变量的 path 添加 `%MDCPP%`
    ![](https://i.loli.net/2021/08/23/QHDb9JKd4I3uBUl.png)
    ![](https://i.loli.net/2021/08/23/H1AqWkc4UiyCB9Q.png)


#### 完成以上步骤后重启 vscode 即可使用。

## 如果需要自行添加库函数，可以按以下步骤操作

1. 以头文件的形式编写代码，然后保存在 `include` 目录中
2. 修改 `header.h` ，添加包含自定义的文件


## 使用教程

本人编写的 `适用于 MPE 的 c++ 代码` 目前有多种运行模式，接下来将一一介绍

### 语句模式

直接写语句，直接运行

```cpp{cmd=run}
cout << "Hello World!" << endl;
```

---

### 完整代码模式

需要写完整的 cpp 代码

注释是标记，必须输入

```cpp{cmd=run}
//all
#include <iostream>
int main(){
    std::cout << "full code mode";
    return 0;
}
```

---

### 类模式

包含了类的定义，和测试两个模块，建议在数据结构笔记中使用

```cpp{cmd=run}
//define
class Student{
public:
    int grade;
    int test(){return grade;}
};
//test
Student a{100};
cout << a.test();
```

---

### 算法测试模式

包含了算法函数，算法入口函数（输入输出的处理），测试数据

带有一个简单的时间计算

//entry 下的语句是算法的入口，算法的参数都需要用户自行处理，此处会提供两个对象：`input` 和 `output`，当作 `cin` 和 `cout` 使用即可，后面的使用格式可以完全照搬下面这个

```cpp{cmd=run}
//sf
int sum(int a, int b){
    return a+b;
}
//entry
int a, b;
input >> a >> b;
if(input)
    output << sum(a, b);
//test
1 1
2 5
10 10
```

本人编写额外提供了一些输入输出函数，其中有对 vector 的处理，以下面的例子说明

计算容器中所有数据的和

```cpp{cmd=run}
//sf
int sum(vector<int> v){
    int sum = 0;
    for(int i = 0; i < v.size(); ++i){
        sum += v[i];
    }
    return sum;
}
//entry
vector<int> v;
input >> v;
if(input)
    output << sum(v);
//test
[1,2,3,4,5]
[10,20,30,40,50]
```

连接容器中的所有字符串

```cpp{cmd=run}
//sf
string connect(vector<string> v){
    string res("");
    for(int i = 0; i < v.size(); ++i){
        res += v[i];
    }
    return res;
}
//entry
vector<string> v;
input >> v;
if(input)
    output << connect(v);
//test
[a,b,c,d,e]
[10,20,30,40,50]
[He,ll,o,Wor,ld!]
```
