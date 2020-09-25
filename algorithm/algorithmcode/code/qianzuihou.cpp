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