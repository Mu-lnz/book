#ifndef SOLUTION_H
#define SOLUTION_H
#include<vector>
#include<unordered_set>
using namespace std;

class Solution{
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k){
        unordered_set<int>usi;
        for(int i=0;i<nums.size();i++){
            if(usi.find(nums[i])!=usi.end())
                return true;
            usi.insert(nums[i]);
            if(usi.size()>k)
                usi.erase(nums[i-k]);
        }
        return false;
    }
};
#endif 