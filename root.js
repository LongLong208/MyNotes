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
