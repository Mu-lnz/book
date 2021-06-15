#include<iostream>
#include<algorithm>
#include<cstdio>
#include<map>
#include<vector>

using namespace std;

typedef long long ll;

ll n, k = 0;

int main(){
    scanf("%lld", &n);
    map<ll, ll>mp;
    vector<ll>v(n, 0);
    vector<ll>p(n + 1, 0);
    for(int i = 0 ; i <n; i ++){
        ll v;
        scanf("%lld", &v);
        p[i + 1] += v + p[i];
        mp[p[i + 1]] ++;
    }
    for(auto e:mp){
        if(e.first ==0)
            k += e.second;
        else if(e.first != 0 && e.second > 1)
            k += e.second/2;
    }
    cout<<k<<endl;
    return 0;
}