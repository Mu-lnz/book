#ifndef SOLUTION_H
#define SOLUTION_H
#include<iostream>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<sstream>
#include<map>
#include<unordered_map>
using namespace std;

class Solution{
public:
    bool find132pattern(vector<int>& nums) {
        if(nums.size()<3)
            return false;
        stack<int>max;
        int second=INT_MIN;
        for(int i=nums.size()-1;i>=0;i--){
            if(nums.at(i)<second)
                return true;
            while(!max.empty()&&max.top()<nums.at(i)){
                second=max.top();
                max.pop();
            }
            max.push(nums.at(i));
        }
        return false;
    }
};
#endif 