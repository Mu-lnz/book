#include<iostream>
#include<algorithm>

using namespace std;

const int N = 100004;
int a[N];

int main(){
    int n, m;
    int res = 0;
    cin>>n>>m;
    for(int i = 0; i < n; i ++){
        int x;
        cin>>x;
        if(x > m) 
            a[i] ++;
        else if(x < m)
            a[i] --;
    }
    for(int i = 1; i <= n; i ++){
        a[i] += a[i - 1];
    }
    
    cout<<res<<endl;
    return 0;
}