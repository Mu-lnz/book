#include<iostream>
#include<algorithm>
#include<math.h>

using namespace std;
const int N = 1200;
int a[N][N];
int n;

void dfs(int x1, int y1, int x2, int y2, int cnt){
    if(cnt >= n) return;
    if(x1 >= x2 || y1 >= y2 || x1 > n || y2 > n)
        return;
    for(int i =  x1; i <= (x2-x1)/2 + x1; i ++){
        for(int j = y1; j <= (y2-y1)/2 + y1; j ++){
            a[i][j] = 1;
        }
    }

    dfs(x1, (y2 - y1 + 1) / 2 + y1, (x2 - x1 + 1) / 2 + x1- 1, y2, cnt + 1);
    dfs((x2 - x1 + 1) / 2 + x1, y1, x2, (y2 - y1 + 1) / 2 + y1 - 1, cnt + 1);
    dfs((x2 - x1 + 1) / 2 + x1, (y2 - y1 + 1) / 2 + y1, x2, y2, cnt + 1);
    
}

int main(){
    cin>>n;
    n = pow(2, n);
    dfs(1, 1, n, n, 1);
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= n; j ++){
            int k = a[i][j];
            k = k ^1;
            cout<<k<<" ";
        }   
        cout<<endl;
    }
    return 0;
}