/** 
 * 引入其他笔记文件
 * @param {str} path 引入文件的路径
 * @param {str} elementId 被引入的标签元素 ID
 */
function importMD(path, elementId)
{
    let e = document.getElementById(elementId)
    e.innerHTML += `<!-- @import '${path}.md' -->`
    e.innerHTML += `[[path]]`
}


/* 调整表格 */
function betterTableColor(){
    var e = document.getElementsByTagName('tbody')
    for (let i = 0; i < e.length; ++i)
    {
        let el = e[i].children
        for (let j = 0; j < el.length; ++j)
        {
            let color
            let fontColor
            if (j % 2 === 0) {
                color = '#383032'
                fontColor = '#e06c88'
            } else {
                color = '#323830'
                fontColor = '#88e06c'
            }
            el[j].style['background-color'] = color
            el[j].style['color'] = fontColor
        }
    }
}


/* 调用一次 */
let t1 = setTimeout(()=>{
    betterTableColor()
    clearTimeout(t1)
}, 250)
