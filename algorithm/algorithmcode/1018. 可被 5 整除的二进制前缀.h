#ifndef SOLUTION_H
#define SOLUTION_H
#include<vector>
using namespace std;

class Solution{
public:
        vector<bool> prefixesDivBy5(vector<int>& A){
        int sum=0;
        vector<bool>vb;
        for(int i=0;i<A.size();i++){
            sum=sum*2+A[i];
            sum%=5;
            if(sum==0)
                vb.push_back(true);
            else
                vb.push_back(false);
        }
        return vb;
    }
};
#endif 