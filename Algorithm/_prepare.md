### Algorithm prepare

---

<br>

随机数生成器

``` cpp {cmd="cppsl"}
srand(time(NULL));
cout << "今天做 " <<(rand()%100*100 | rand()%100 );
```

