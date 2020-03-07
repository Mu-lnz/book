#ifndef SOLUTION_H
#define SOLUTION_H
#include<queue>
#include<deque>
using namespace std;

class MaxQueue {
public:
    queue<int>qi;
    deque<int>de;

    MaxQueue() {

    }
    
    int max_value() {
        if(de.empty())
            return -1;
        return de.front();
    }
    
    void push_back(int value) {
        qi.push(value);
        while(!de.empty()&&de.back()<value){
            de.pop_back();
        }
        de.push_back(value);
    }
    
    int pop_front() {
        if(qi.empty())
            return -1;
        if(qi.front()==de.front())
            de.pop_front();
        int ans=qi.front();
        qi.pop();
        return ans;
    }
};
#endif