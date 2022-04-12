<!-- @import "/root.css" -->

## A^*^

每次选择时，对于当前选择的节点 `node` 有：
- 代价 `G`： 起点到 `node` 的距离
- 代价 `H`：  `node` 到终点的距离
- 代价 `F`： `F = G + H`


代价 G 算法：上下左右为 10， 斜线为14
代价 H 算法：曼哈顿距离（水平与垂直距离之和）s

算法思路：
```cpp
初始化
    优先队列 open， 记录待遍历节点（边界）
    列表 close，记录已遍历节点
    G(start) = 0
    open.push(start)

当 open 不为空：
    cur = open.first()
    if (cur == end)
        break
    open.remove(cur)
    close.push(cur)
    for (next : neighbors(cur)) {
        if (close.contains(next))
            continue
        if (!open.contains(next))
        {
            next.parent = cur
            next.cost = G(cur) + Cost(cur, next) + H(next)
            open.push(next)
        }
    }


```
