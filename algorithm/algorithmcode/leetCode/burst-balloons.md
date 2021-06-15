# 戳气球

本题为区间`dp`问题

那么我们可以看向一道题[合并石子](https://blog.csdn.net/acdreamers/article/details/18039073)

1. 设置最终到达的状态 c[l, r]，那么它的前一个状态为什么？

2. c[l, r] 的前一个状态的属性为`max`，有 `c[l, r] = max(c[l, i] + c[i, r] + conin[l] * conin[i] * conin[r])`，解释：前一个状态的左边最大值和右边最大值在加上当前状态的最大值.

3. 注意范围，当 l >= r - 1 时，在这一段子数组中没有值.

代码：

```c++
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        vector<vector<int>>f(n + 2, vector<int>(n + 2));
        for(int l = n - 1; l >= 0; l --){
            for(int r = l + 1; r < n + 2; r ++){
                for(int i = l + 1; i < r; i ++){
                    f[l][r] = max(f[l][r], f[l][i] + f[i][r] + nums[l] * nums[i] * nums[r]);
                }
            }
        }
        return f[0][n + 1];
    }
};

```