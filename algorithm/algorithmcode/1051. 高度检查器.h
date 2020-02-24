#ifndef SOLUTION_H
#define SOLUTION_H
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
public:
    int heightChecker(vector<int>& heights){
        vector<int>vi(heights);
        sort(heights.begin(),heights.end());
        int count=0;
        for(int i=0;i<heights.size();i++){
            if(heights[i]!=vi[i])
                count++;
        }
        return count;
    }
};
#endif 