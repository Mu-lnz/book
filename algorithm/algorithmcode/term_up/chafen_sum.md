## 前缀和公式：

一维前缀和：

```c++
S[i] = a[1] + a[2] + ... a[i]
a[l] + ... + a[r] = S[r] - S[l - 1]
```

二维前缀和：
```c++
b[i][j] =a[i][j] + b[i][j - 1] + b[i - 1][j] - b[i - 1][j - 1];
//当前和为左边上边相加再减去两者相互覆盖的 b[i - 1][j - 1]
```

[P3397 地毯](https://www.luogu.com.cn/problem/P3397)

* 原始代码
```C++
#include<iostream>
#include<algorithm>

using namespace std;

const int N = 1004;
int a[N][N];
int n, m;

void insert(int x1, int y1, int x2, int y2){
    for(int i = x1; i <= x2; i ++){
        for(int j = y1; j <= y2; j ++)
            a[i][j] += 1;
    }  
}

int main(){
    cin>>n>>m;
    int x1, y1, x2, y2;
    for(int i = 0; i < m; i ++){
        cin>>x1>>y1>>x2>>y2;
        insert(x1, y1, x2, y2);
    }

    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= n; j ++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
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
## 二维前缀和


