#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 101000;
int b[N], idx[N], n;

int read(){
    int x = 1, f = 0;
    char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
    while('0' <= ch && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
    return x * f;
}

int main(){
    n = read();
    for(int i = 1; i <= n; i ++)
        idx[read()];

    for(int i = 1; i <= n; i ++){
        int x = idx[read()];
        *lower_bound(b + 1, b + n + 1, x) = x;
    }
    printf("%d",lower_bound(b+1,b+n+1,b[0])-b-1);
    return 0;
}