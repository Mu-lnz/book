#ifdef Bracket_Matching
#define BRACKET_MATCHING
#include<string>
#include<stack>
using namespace std;

class Bracket
{
    public:
    bool isValid(string s){
        stack<char>sta;
        if(s.empty())
            return true;
        if(s.size()%2==1)
            return false;
        for(int i=0;i<s.size();i++){
            if(s.at(i)=='('||s.at(i)=='['||s.at(i)=='{')
                sta.push(s.at(i));
            else{
                if(sta.empty())
                    return false;
                if((s.at(i)==')'&&sta.top()!='(')||(s.at(i)=='}'&&sta.top()!='{')
                ||(s.at(i)==']'&&sta.top()!='['))
                    return false;
                sta.pop();
            }
        }
        return sta.empty();
    }
};

#endif
