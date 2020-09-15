## 双指针

题目应用：

[3数之和](https://leetcode-cn.com/problems/3sum/)

本题核心为双指针，但是需要对每一层进行修剪（指当相邻两个数相同时跳过当前数），同时注意双指针的方向，本题为从右向左移动（有些题目可能是从左向右移动）

代码如下：

```
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>res;
        map<vector<int>, int> mp;
        sort(nums.begin(), nums.end());
        for(int k = 0; k < n; k++){
            if(k > 0 && nums[k] == nums[k - 1])
                continue;
            int target = -nums[k];
            int j = n - 1;
            for(int i = k + 1, j = k + 2; i < n; i ++){
                if (i > k + 1 && nums[i] == nums[i - 1])
                    continue;
                while(k < n && nums[i] + nums[j] <= target)
                    j ++;
                if(j == i)
                    break;
                if(nums[i] + nums[j] == target)
                    res.push_back({-target, nums[i], nums[j]});
            }
        }
        return res;
    }
};
```