#ifndef SOLUTION_H
#define SOLUTION_H
#include<algorithm>
#include<vector>
using namespace std;

class Solution{
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        vector<int>ve;
        int last_name=K,i=A.size()-1;
        while(i>=0||last_name>0){
            if(i>=0)
                last_name+=A[i--];
            ve.push_back(last_name%10);
            last_name/=10;
        }
        reverse(ve.begin(),ve.end());
        return ve;
    }
};
#endif 