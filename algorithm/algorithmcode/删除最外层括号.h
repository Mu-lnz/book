#ifdef Bracket_Matching
#define BRACKET_MATCHING
#include<string>
#include<stack>
using namespace std;

class Bracket
{
    public:
   //1021.删除最外层括号
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