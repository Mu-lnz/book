#include<iostream>
#include<algorithm>

using namespace std;

const int N = 102000;
int h[N], ne[N], e[N], idx;
int n;

void insert(int a,int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

int main(){
    cin>>n;
    for(int i = 0; i < n; i ++){
        int a, b;
        cin>>a>>b;
        h[a][b] = 1;
        q[b] ++;
    }
    for(int i = 0; i < 1700; i ++){

    }
    return 0;
}