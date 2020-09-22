#include<iostream>
#include<algorithm>

using namespace std;

const int N = 1000010;
int a[N], t[N];
int n, b;

bool caculate(const int l, const int r){
    int len = r - l;
    for(int i = 0, j = l; i < len; i ++)
        t[i] = a[j];
    sort(t, t + len);
    len = len / 2 + 1;
    return t[len] == b;
}

int main(){
    scanf("%d%d", &n, &b);
    int res = 0;
    for(int i = 1; i <= n; i ++)
        scanf("%d", &a[i]);
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <i; j++){
            if(caculate(j, i))
                res ++;
        }
    }
    cout<<res<<endl;
    return 0;
}