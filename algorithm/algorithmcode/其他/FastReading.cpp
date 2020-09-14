#include<bits/stdc++.h>
using namespace std;

int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}

int main(){
    long long num;
    int i=0;
    while(i<10){
        num=read();
        cout<<num<<endl;
        i++;
    }
    return 0;
}