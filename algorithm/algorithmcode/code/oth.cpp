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