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
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2){
        unordered_map<int,int>hs;
        vector<int>nums;
        int k=0;
        for(auto e:nums2)
            hs[e]=k++;
        for(auto e:nums1){
            for(int i=hs[e];i<nums2.size();i++){
                if(e<nums2.at(i)){
                    nums.push_back(nums2.at(i));
                    break;
                }
                else if(i==nums2.size()-1)
                    nums.push_back(-1);
            }
        }
        return nums;
    }
};
#endif 