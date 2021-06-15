#include<iostream>
#include<algorithm>

using namespace std;

const int N = 2004, INF = 0x3f3f3f3f;
int n, m;
int a[N][N], f[N][N];

int main(){
    cin>>n>>m;
    for(int i = 1; i <= m; i ++)
        for(int j = 1; j <= n; j++)
            cin>>a[j][i];
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= m; j ++)
            f[i][j] = min(f[i - 1][j], j == 1 ? f[i - 1][m] : f[i - 1][j - 1]) + a[i][j];
    int ans = INF;
    for(int i = 1; i <= m; i ++)
        ans = min(ans, f[n][i]);
    cout<<ans; 
    return 0;
}