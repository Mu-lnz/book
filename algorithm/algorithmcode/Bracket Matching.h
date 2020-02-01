#ifdef Bracket_Matching
#define BRACKET_MATCHING
#include<string>
#include<stack>
using namespace std;

class Bracket
{
    public:

    //¿®∫≈∆•≈‰
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

    //1021. …æ≥˝◊ÓÕ‚≤„µƒ¿®∫≈
    string removeOuterParentheses(string S){
        int L=1,R=0;
        string st;
        for(int i=1;i<S.size();i++){
            if(S.at(i)=='(')
                L++;
            else{
                R++;
            }

            if(L!=R)
                st.push_back(S.at(i));
            else{
                i++;
                L=1;
                R=0;
            }
        }
        return st;
    }
};

#endif
