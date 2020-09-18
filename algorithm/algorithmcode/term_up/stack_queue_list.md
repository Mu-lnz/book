## 1. 单调栈

单调栈中按照某一种性质单调递增或递减

```
while(st.size() && check())
    st.pop();
st.push(element)
```
应用：

#### <font color = red>题目1：</font>[123模式](https://leetcode-cn.com/problems/132-pattern/)

在本题中，单调栈用于寻找第三个数，使用单调递减的栈从最后的数开始读入，如果在数列中出现了还比第三个数还小的数，那么就一定会存在（第三数初始值为`INT_MAX`，在这之前已经把 `INT_MAX`更新了）.


源码：
```c++
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int minf = INT_MIN;
        stack<int> st;
        int n = nums.size();
        for(int i = n - 1; i >= 0; i --){
            if(nums[i] < minf) return true;
            while(st.size() && st.top() < nums[i]){
                minf = st.top();
                st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};
```

#### <font color = red>题目2：</font>[柱状图中最大的矩形](https://leetcode-cn.com/problems/largest-rectangle-in-histogram/)

 本题使用单调递增栈，单调栈主要用来记录每一个下标，同时注意求出最后一组单调序列

```c++
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>q;
        int res = 0;
        for(int i = 0; i < heights.size(); i++){
            while(q.size() && heights[q.top()] > heights[i]){
                int hight = heights[q.top()];
                q.pop();
                int l = i;//用于水平长度
                if(q.size()){
                    l = i - q.top() - 1;
                }
                res = max(res, l * hight);
            }
            q.push(i);
        }
        while(q.size()){
                int hight = heights[q.top()];
                q.pop();
                int l = heights.size();
                if(q.size()){
                    l = heights.size() - q.top() - 1;
                }
                res = max(res, l * hight);
            }
        return res;
    }
};
```

### <font color = red>题目3：</font> [接雨水](https://leetcode-cn.com/problems/trapping-rain-water/)

</br>

## 单调队列

单调队列常用与滑动窗口
