## 前缀和公式：

一维前缀和：

```c++
S[i] = a[1] + a[2] + ... a[i]
a[l] + ... + a[r] = S[r] - S[l - 1]
```

一维差分：

```c++
给区间[l, r]中的每个数加上c：B[l] += c, B[r + 1] -= c
```
<font color=red>题目1：</font>[CF44C Holidays](https://www.luogu.com.cn/problem/CF44C)

```C++
#include<iostream>
#include<algorithm>

using namespace std;

const int N = 1e6 + 1;
int ar[N];
int n, m;

void Insert(int l, int r){
    ar[l] += 1;
    ar[r + 1] -= 1;
}

int main(){
    bool st = 0;
    scanf("%d%d", &n, &m);
    while(m--){
        int a, b;
        scanf("%d%d", &a, &b);
        Insert(a, b);
    }
    for(int i = 1; i <= n; i++){
        ar[i] += ar[i - 1];
    }
    for(int i = 1; i <= n; i ++){
        if(ar[i] != 1){
            printf("%d %d\n", i, ar[i]);
            st = 1;
            break;
        }
    }
    if(st == 0) puts("OK");

    return 0;
}
```

