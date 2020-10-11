
* 欧拉路径：通过图中所有边一次且仅一次遍历所有顶点的路径称为欧拉(Euler)路径；
* 欧拉回路：通过图中所有边一次且仅一次行遍所有顶点的回路称为欧拉回路；
* 欧拉图：具有欧拉回路的图称为欧拉图；
* 半欧拉图：有欧拉路径但没有欧拉回路的图称为半欧拉图。


### Hierholzer 算法

[地址](https://www.jianshu.com/p/8394b8e5b878)


欧拉图的充要条件：
    G是欧拉图\LeftrightarrowG是若干个边不重的圈(环)的并，
    我们可以先找到一个环，而剩下的边一定还存在环，且这两个部分必有公共点，
    从而可以形成更大的环，这样直到包括所有边，即可找到欧拉回路。

```c++
class Solution {
private:
    unordered_set<int> seen;
    string ans;
    int highest;
    int k;

public:
    void dfs(int node) {
        for (int x = 0; x < k; ++x) {
            int nei = node * 10 + x;
            if (!seen.count(nei)) {
                seen.insert(nei);
                dfs(nei % highest);
                ans += (x + '0');
            }
        }
    }

    string crackSafe(int n, int k) {
        highest = pow(10, n - 1);
        this->k = k;
        dfs(0);
        ans += string(n - 1, '0');
        return ans;
    }
};
```