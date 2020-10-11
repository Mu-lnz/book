
#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;

const int N = 5004;

typedef long long ll;

int re[3][6];
int problem[N];
int n;
int m[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

/*
# 闰年：
# 1. 该年份能被4整除同时不能被100整除.
# 2. 该年份能被400整除.
*/

bool dg(int y){
    if(y % 4 == 0 && y % 100 != 0) return true;
    if(y % 400 == 0) return true;
    return false;
}

ll day(int p){
    int ru = 0;
    for(int i = 0; i < re[p][1]; i ++){
        if(dg(i) && i < re[p][1])
                ru ++;
    }
    ll y = 365 * re[p][1] + ru;
    for(int i = 1; i <= re[p][2]; i ++){
        y += m[i - 1];
    }
    cout<< y<<" ";
    y = y * 60 * 24 + re[p][4] * 60 + re[p][5];
    return y;
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i ++)
        scanf("%d", &problem[i]);
    sort(problem, problem + n);
    scanf("%d-%d-%d-%d:%d", &re[0][1], &re[0][2], &re[0][3], &re[0][4], &re[0][5]);
    scanf("%d-%d-%d-%d:%d", &re[1][1], &re[1][2], &re[1][3], &re[1][4], &re[1][5]);
    
    ll m1 = day(0), m2 = day(1);
    ll mt = m2 - m1, res = 0;
    cout<<mt<<endl;
    for(int i = 0, sum = 0; i < n; i ++){
        sum += problem[i];
        if(sum > mt){
            res = i;
            break;
        }
    }
    cout<<res<<endl;
    return 0;
}
