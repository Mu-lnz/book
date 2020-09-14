#ifndef SOLUTION_H
#define SOLUTION_H
#include<unordered_map>
#include<vector>
using namespace std;

class Solution{
public:
    int majorityElement(vector<int>& nums) {
        int count=1;
        int num=nums[0];
        for(int i=1;i<nums.size();i++){
            if(count==0){
                num=nums[i];
                count=1;
            }
            else if(num==nums[i])
                count++;
            else
                count--;
        }
        return num;
    }

    int majorityElement2(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
            if(mp[nums[i]]>nums.size()/2)
                return nums[i];
        }
    }
};
#endif 