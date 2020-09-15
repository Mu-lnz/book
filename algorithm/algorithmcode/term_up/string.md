## 知识点1：考察字符串的比较

    两个字符串中比较字符串的大小，是按照字典序列进行比较
    
    <font color=red>应用</font>：字符串交换比较 a1 + a2 与 a2 + a1 进行比较
    
    如："20" 与 "21" 的字符串比较，明显在通过两次相加后是不同的，分别是“2021”和“2120” 

题目：[最大数](https://leetcode-cn.com/problems/largest-number/)

源代码：

```c++
class Solution {
public:
     static bool check(const int  a, const int b) {
        return to_string(a) + to_string(b) > to_string(b) + to_string(a);
    }

    void Qsort(vector<int>&nums, int l, int r){
        if(l >= r) return;
        int i = l - 1, j = r + 1, x = nums[(l + r) >> 1];
        while(i < j){
            do i ++; while(check(nums[i], x));
            do j --; while(check(x, nums[j]));
            if(i < j) swap(nums[i], nums[j]);
        }
        Qsort(nums, l, j);
        Qsort(nums, j + 1, r);
    }
    string largestNumber(vector<int>& nums) {
        Qsort(nums, 0, nums.size() - 1);
        string str;
        if (nums[0] == 0) return "0";
        for(auto e:nums)
            str += to_string(e);
        return str;
    }
};
```