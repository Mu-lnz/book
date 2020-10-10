#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <cstdio>
#include <vector>

using namespace std;

int main(){
    string ss;
    map<char, int>mci;
    int cot = 0;
    cin>>ss;
    for(int i = 0; i < ss.size(); i++){
        mci[ss[i]] ++;
    }
    cot = mci.size();
    if(cot&1)
        printf("IGNORE HIM!\n");        
    else 
        printf("CHAT WITH HER!\n");

    return 0;
}