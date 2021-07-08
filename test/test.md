```cpp {cmd="cppmd.bat" hide modify_source run_on_save}
#include <iostream>
using namespace std;
int main(){
    cout<<"# Hello World!";
    return 0;
}
```

<!-- 这里是由上面代码生成的！ -->
<!-- code_chunk_output -->

# Hello World!

<!-- /code_chunk_output -->

---
#### c++完整代码
<!-- continue本质是把代码拼在一起 -->
```cpp {cmd="cppmd.bat" id="izdlk700"}
#include <iostream>
using namespace std;
int main(){
    cout<<"1";
```
```cpp {cmd="cppmd.bat" continue="izdlk700"}
    cout<<"2";
    return 0;
}
```

---
#### c++语句
<!-- 本质是把这些代码嵌入到main函数中执行 -->
```cpp {cmd="cppsl"}
cout<<"C++ single line"<<endl;
cout<<1+2+3+4+5;
```




---
#### JS
```javascript {cmd="node"}
const date = Date.now();
console.log(date.toString());
```
---
#### Python
```python {cmd}
# coding=utf-8
s="this will run python3 program"
print(s)
```
