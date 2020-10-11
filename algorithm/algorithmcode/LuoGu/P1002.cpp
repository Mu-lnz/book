#include<iostream>
#include<cstdio>

using namespace std;

typedef long long ll;
const int N = 23;

int n, m, n1, m1;
ll g[N][N];

void dj(ll pos[][2]){
    for(int i = 0; i < 9; i ++){
        if(pos[i][0] == 0 || pos[i][1] == 0)
            g[pos[i][0]][pos[i][1]] = 0;
        cout<<"("<<pos[i][0]<<", "<<pos[i][1]<<") ";
    }
}

bool find(ll pos[][2],int x, int y){
    for(int i = 0; i < 9; i ++){
        if(pos[i][0] == x && pos[i][1] == y) 
            return false;
    }
    return true;
}

int main(){
    
    scanf("%d%d%d%d", &n, &m, &n1, &m1);
    int pos[9][2] = {{n1 -1, m1 - 2}, {n1 + 1, m1 - 2}, 
                 {n1 -1, m1 + 2}, {n1 + 1, m1 + 2},
                 {n1 +2, m1 + 1}, {n1 + 2, m1 - 1},
                 {n1 -2, m1 - 1}, {n1 - 2, m1 + 1},
                 {n1, m1}};

    for(int i = 0; i <= n; i ++) 
        g[i][0] = 1;
    for(int j = 0; j <= m; j ++)
        g[0][j] = 1;
    dj(pos);
    cout<<endl;
    find(pos, n1, m1);
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j ++){
            if(find(pos, i, j))
                g[i][j] = g[i][j - 1] + g[i - 1][j];
        }
    }
    for(int i = 0; i <= n; i ++){
        for(int j = 0; j <= m; j ++)
            cout<<g[i][j]<<" ";
        cout<<endl;
    }
    printf("%ll\n", g[n][m]);
    return 0;
}