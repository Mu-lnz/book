#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 100010;


int main()
{
    int T, n;
    cin>>T;

    int res = 0;
    while (T -- )
    {
        cin>>n;
        while(n --){
            int x;
            cin>>x;
            res ^= x;
        }
        if (res) cout<<"Yes"<<endl;
        else cout<<("No\n")<<endl;
    }
    return 0;
}