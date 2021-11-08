<!-- @import "../.mytool/_pre.css" -->

<script>
  function show(id){
    var e = document.getElementById(id);
    e.style['color']='#f8f8f2';
  }
  function hide(id){
    var e = document.getElementById(id);
    e.style['color']='#282828';
  }
</script>

<style>
html body .recite{
  color: #282828;
  border: 1px dotted white;
}
</style>

## 软件测试概述

### 软件缺陷特征

<div class=recite id=软件缺陷特征 onmouseover=show('软件缺陷特征') onmouseout=hide('软件缺陷特征')>

- 不易找到；不易找到原因
- 发现越早，代价越小

</div>

### 软件测试定义

<div class=recite id=软件测试定义 onmouseover=show('软件测试定义') onmouseout=hide('软件测试定义')>

- 定义1：检验是否满足需求，或是弄清预期与实际差别
- 定义2：用测试用例执行程序以发现故障
- 定义3：通过经济有效的方法，发现软件缺陷，保证软件质量
  
</div>

### 软件测试目的
<div class=recite id=软件测试目的 onmouseover=show('软件测试目的') onmouseout=hide('软件测试目的')>

- 发现错误，而不是证明程序正确性
- 是否满足需求
- 发现错误，而不能说明错误不存在
  

</div>

一个好的测试用例在于发现了还未曾发现的错误；一次成功的测试则是发现了错误的测试

### 软件测试模型

#### V 模型


![](https://i.loli.net/2021/11/06/miUXPduszJea5xT.png)


<br><hr>

## 软件测试计划

测试计划原则：尽早、灵活、简洁易读、多渠道评审、计算投入

<br><hr>

## 黑盒测试

### 测试用例


是一组测试输入、执行条件和预期结果，目的是要满足一个特定的目标，比如执行一条特定的程序路径或检验是否符合一个特定的需求


测试用例是执行的最小实体，是软件测试的关键

### 黑盒测试

又称功能测试，与软件实现无关

### 等价类测试



测试等价类的代表值，就等效于对这个等价类中其他值的测试

<div class=recite id='等价类测试' onmouseover=show('等价类测试') onmouseout=hide('等价类测试')>

- 有效等价类：对需求来说是合理的、有意义的输入数据集合；
  用于检测程序的预期功能和性能
- 无效等价类：对需求来说是不合理、无意义的输入数据集合；
  用于检测程序对无效数据的处理能力

</div>

### 边界值分析法

故障往往发生在定义域、值域边界上
单缺陷假设：失效极少是由两个或多个缺陷的同时发生引起的

测试用例的设计


<div class=recite id='边界值分析法' onmouseover=show('边界值分析法') onmouseout=hide('边界值分析法')>

- 最小值、略高于最小值、正常值、略低于最大值、最大值
  \(4n+1\)
  \(x_{min}~x_{min+}~x_{nom}~x_{max-}~x_{max}\)
- 健壮性测试用例：\(6n+1\)

</div>
### 判定表

![](https://i.loli.net/2021/11/07/bVxZjBfzvwdLPDM.png)

规则：条件取值 + 操作

规则合并（简化）条件：相同的动作和相似的条件

### 因果图

步骤：
1. 分析原因和结果
2. 找出原因与结果、原因与原因的关系
3. 画出因果图
4. 转换为决策表
5. 为决策表的每一条规则设计测试用例

<br><hr>

## 白盒测试

白盒测试：逻辑覆盖 + 路径覆盖

覆盖从低到高：
<div class=recite id='覆盖从低到高：' onmouseover=show('覆盖从低到高：') onmouseout=hide('覆盖从低到高：')>

- 语句覆盖
- 判定覆盖
- 条件覆盖
- 判定/条件覆盖
- 条件组合覆盖
- 路径覆盖

</div>
### 基本路径测试方法

步骤：
<div class=recite id='基本路径测试方法' onmouseover=show('基本路径测试方法') onmouseout=hide('基本路径测试方法')>

1. 画出控制流图
2. 计算环形复杂度：每个语句至少执行一次所需的测试用例数目的上界
3. 导出基本路径集，确定独立路径
4. 设计测试用例

</div>
<br><hr>

## 单元测试

驱动模块：主程序

桩模块：代替被测单元的子模块

### junit 单元测试

断言方法：assertEquals()

<br><hr>

## 集成测试

关注点：模块间的接口，接口之间的数据传递关系，组合后的预计功能

自顶向下：不需要驱动模块
自底向上：不需要桩模块
三明治：都需要，但是工作小；但是定位缺陷的难度增加

<br><hr>

## 系统测试

测试是否满足需求


### 功能测试

#### 链接（界面切换）测试
测试页面间的链接
是否有孤立页面

#### 业务流程测试
基于用例场景设计测试用例


### 性能测试
测试是否满足性能指标
