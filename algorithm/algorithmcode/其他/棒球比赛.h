#ifndef SOLUTION_H
#define SOLUTION_H
#include<iostream>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<sstream>
using namespace std;

class Solution{
public:
    int calPoints(vector<string>& ops){
        if(ops.empty())
            return 0;
        stack<int>res;
        int result=0;
        for(int i=0;i<ops.size();i++){
            const char *p=ops.at(i).data();
            switch(*p){
                case '+':{
                    if(res.empty())
                        res.push(0);
                    else if(res.size()==1)
                        res.push(res.top());
                    else{
                        int count=res.top();
                        res.pop();
                        int nowcount=count+res.top();
                        res.push(count);
                        res.push(nowcount);
                    }
                    result+=res.top();
                    continue;
                }
                case 'D':{
                    if(res.empty())
                        res.push(0);
                    else{
                        res.push(res.top()*2);
                        result+=res.top();
                    }
                    continue;
                }
                case 'C':{
                    if(res.empty())
                        res.push(0);
                    else{
                        result-=res.top();
                        res.pop();
                    }
                    continue;
                }
                default:{
                    stringstream ss(ops.at(i));
                    int t;
                    ss>>t;
                    res.push(t);
                    result+=res.top();
                }
            }
        }
        return result;
    }
};
#endif 