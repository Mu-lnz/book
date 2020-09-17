## 拓扑序

题型1：拓扑排序

[课程表 II](https://leetcode-cn.com/problems/course-schedule-ii/)

首先标记每一个节点有多少个入度，然后把所有入度为0的节点放到一个队列中

使用广度优先搜索，从队头取出的数构成一个拓扑序列

    在广度优先搜索中，每一次循环会减少当前节点的入度数，当当前的节点入度数为0时，加入队列
源码：
```
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>g(numCourses);
        vector<int>res;
        vector<int>edge(numCourses + 1, 0);
        queue<int>q;
        for(auto e:prerequisites){
            g[e[1]].push_back(e[0]);
            ++edge[e[0]];
        }
        for(auto e:)
        for(int i = 0; i < numCourses; i ++){
            if(edge[i] == 0)
                q.push(i);
        }
       while (!q.empty()) {
            int u = q.front();
            q.pop();
            res.push_back(u);
            for (int v: g[u]) {
                --edge[v];
                if (edge[v] == 0) {
                    q.push(v);
                }
            }
        }
        if (res.size() != numCourses) {
            return {};
        }
        return res;
    }
};
```