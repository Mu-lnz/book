## 深度优先搜索

### 二维数组中的深搜

代码模式
```
dfs(){
    if() 出口条件

    遍历当前数组位置的上下左右
    如：dfs(x + 1, y), dfs(x - 1, y), dfs(x, y - 1), dfs(x, y + 1);
}
```

#### 类型1：主要以二维数组的形式出现，要求在这个二维数组中进行查找某条路径.

<font color = red>题目1：</font>[单词搜索](https://leetcode-cn.com/problems/word-search/)

在本题中需要对已经走过的字母进行标记，可以开一个布尔数组，也可以把当前位置变成其他的，然后再变回来

源码：
```
class Solution {
public:

    bool dfs(vector<vector<char>>& board, string &word, int x, int y, int idx){
        if(x >= board.size() || x < 0 || y >= board[0].size() || y < 0 || board[x][y] != word[idx])
            return false;
        if(idx == word.size() - 1)
            return true;
        
        char tmp = board[x][y];
        board[x][y] = '*';
        
        bool res = 
        dfs(board, word, x + 1, y, idx + 1) ||
        dfs(board, word, x - 1, y, idx + 1) ||
        dfs(board, word, x, y + 1, idx + 1) ||
        dfs(board, word, x, y - 1, idx + 1);

        board[x][y] = tmp;  

        return res;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i ++){
            for(int j = 0; j < board[0].size(); j ++){
                if(dfs(board, word, i, j, 0))
                    return true;
            }
        }
        return false;
    }
};
```

#### 题型2：求某个二维数组中连续某`性质`相同的面积大小





### 一维数组的搜索

代码模式：
```
search(arr, x, S){
    1. 查询条件和出口条件

    2. 递归
        search(arr, arr[i] + x, S) ...
}
```


<font color=red>题目1：</font>[目标和](https://leetcode-cn.com/problems/target-sum/)

```
class Solution {
public:
    int cot = 0;
    void search(vector<int>& nums, int i, int sum, int S) {
        if (i == nums.size()) {
            if (sum == S)
                cot++;
        } else {
            search(nums, i + 1, sum + nums[i], S);
            search(nums, i + 1, sum - nums[i], S);
        }
    }
    int findTargetSumWays(vector<int>& nums, int S) {
        search(nums, 0, 0, S);
        return cot;
    }
};
```

