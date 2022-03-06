---
html:
    offline: true

export_on_save:
  html: true
---



# 在 VSCode 中用 Markdown 做「数字化」学习笔记

这里是对原教程的搬运与补充，详情请看 [原教程](https://orangex4.cool/post/notes-in-markdown/)

扩展教程：

- [MPE](https://shd101wyy.github.io/markdown-preview-enhanced/#/zh-cn/)

- [markdown基本语法](https://www.runoob.com/markdown/md-tutorial.html)

---

<br>

## 环境配置：

vscode 下载：[官网](https://code.visualstudio.com/)

vscode 插件安装：

在 vscode 中搜索插件

![image-20210823145749727](https://i.loli.net/2021/08/23/HEXrWfQjYSoxbw8.png)

插件：

- 中文支持：输入 `Chinese` 搜索

- markdown 支持：`Markdown-Notes-Pack`

- 额外插件： `foam`（双链笔记）

![image-20210823145921531](https://i.loli.net/2021/08/23/bGUQqENi5rYsgMX.png)



插件设置


![](https://i.loli.net/2021/08/23/NGUHDPdZgsBAQyI.png)

![](https://i.loli.net/2021/08/23/HczribA2dPms3px.png)

有几个重要的设置项：

1. **`Preview Theme`**
    这个是 markdown 预览的主题颜色，可按照自己喜好调整
2. **`Mermaid Theme`**
    这个是 markdown `mermaid` 图的主题颜色，建议设置为和你的 `Preview Theme` 相容的颜色
3. **`Enable Script Execution`**
    启用脚本，可能会受到攻击，此项启用之后才能使用 MPE 的运行代码段功能
4. **`Enable Extended Table Syntax`**
    启用合并表格单元格功能

安装好之后，新建一个后缀 .md 的文件，然后点击预览，即可开始写作

![](https://i.loli.net/2021/08/23/vpVBqJFG2sxnXad.png)

---

@import "simple.md"
