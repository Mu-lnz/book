#ifndef SOLUTION_H
#define SOLUTION_H
#include<set>
#include<vector>
using namespace std;

class Solution{
public:
    int thirdMax(vector<int>& nums){
        set<int> s(nums.begin(),nums.end());
        if(s.size()<3)
            return *s.rbegin();
        else
            return *(++(++s.rbegin()));
    }
};
#endif 