```mermaid
graph TD;

tk(坦克)

subgraph 0
ym(原木)
sy(石油)
t(铁)
m(煤)
l(铝)
end

subgraph 1
zy(炸药)
mc(木材)
g(钢)
sl(塑料)
end

subgraph 2
qx(枪械)
end

subgraph 3
yq(引擎)
hp(火炮)
end

zy -->|1| m
g -->|2| m
sl --> |2| m
qx -->|1| sl
qx -->|1| g
hp -->|2| g
yq -->|2| g
g -->|4| t
mc -->|2| ym
zy -->|2| ym
zy -->|2| sy
qx -->|1| mc
hp -->|2| zy
hp -->|2| qx
tk -->|2| l
yq -->|1| l
yq -->|1| sl
tk -->|10| m
tk -->|15| g
tk -->|2| yq
tk -->|5| sl
tk -->|2| hp

```

坦克 = 2引擎 + 15钢 + 5塑料 + 2火炮 + 2铝 + 10煤
= 2(2钢 + 铝 + 煤) + 15钢 + 5塑料 + 2(4原木 + 4石油 + 2煤 + 2钢 + 2塑料 + 4原木) + 2铝 + 10煤
= 4钢 + 2铝 + 2煤 + 15钢 + 5塑料 + 16原木 + 8石油 + 4煤 + 4钢 + 4塑料 + 2铝 + 10煤
= 4铝 + 19钢 + 9塑料 + 16原木 + 8石油 + 16煤
= 4铝 + 38铁        + 9塑料 + 16原木 + 8石油 + 35煤
= 4铝 + 29铁 + 10铬 + 9塑料 + 16原木 + 8石油 + 16煤 