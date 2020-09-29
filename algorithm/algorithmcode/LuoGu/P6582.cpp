#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
const int N = 1004;
int g[N][N];
int n, m, k;
int res = 0;

int dfs(int x, int y, int ans){
    if(x < 0 || y < 0 || x >= n || y >= m || g[x][y] != 1)
        return 
}

int main(){
    memset(g, -1, sizeof g);
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < m; j ++){
            char color;
            color = getchar();
            if(color == 'O')
                g[i][j] = 0;
            else 
                g[i][j] = 1;
        }
    }
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < m; j++){
            if(g[i][j] == 0){
                int p = dfs(i, j, 0);

            }
        }
    }
    return 0;
}