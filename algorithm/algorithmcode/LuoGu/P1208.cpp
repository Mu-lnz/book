#include<iostream>
#include<algorithm>

using namespace std;

const int N = 5010;
int n, m;
int p[N], c[N];
int f[N][N];

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; i++) scanf("%d%d", &p[i], &c[i]);
    for(int i = 1; i <= m; i ++){
        for(int j = 0; j <= n; j ++){
            f[i][j] = f[i - 1][j];
            if(j >= p[i])
                f[i][j] = max(f[i][j], f[i][j - p[i]] + c[i]);
        }
    }
    printf("%d\n", f[m][n]);
    return 0;
}