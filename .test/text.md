<br>
<br>


```cpp{cmd=run}
//all
#include <iostream>
using namespace std;

int main(){
    cout << "Hello World!" << endl;
    return 0;
}
```


```cpp{cmd=run}
cout << "Hello World!" << endl;
cout << 1+1 << endl;
```

```cpp{cmd=run}
//sf
int sum(int a, int b){
    return a + b;
}
//entry
int a, b;
input >> a >> b;
if(input)
output << sum(a, b);
//test
1 2
3 4
```

```cpp{cmd=run}
//class
class c{
public:
    int num;
};
//use
c a{6};
if(a.num == 6)
    ++a.num;
cout << a.num << endl;
```

```cpp{cmd=run}
//sf
int sum(int a, int b){
    return a + b;
}
//entry
vector<int> v;
input >> v;
if(input)
output << v;
//test
[1,2,3,4]
```


```cpp{cmd=run}
//all
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
char *pathvar;
pathvar = getenv("MDCPP");
printf("pathvar = %s",pathvar);
return 0;
}
```

```cpp{cmd=run}
//sf
//entry
vector<vector<vector<vector<int>>>>  a;
input >> a;
if(input)
    output << a;
//test
[
    [
        [
            [1,8],
            [2]
        ],
        [
            [3],
            [4]
        ]
    ]
]
```
