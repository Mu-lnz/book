## 1. 栈

单调栈

单调栈中按照某一种性质单调递增或递减

```
while(st.size() && check())
    st.pop();
st.push(element)
```
应用：

[123模式](https://leetcode-cn.com/problems/132-pattern/)

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


