#ifndef SOLUTION_H
#define SOLUTION_H
#include<vector>
using namespace std;

class Solution{
public:
    int maxProfit_1(vector<int>& prices){
        if(prices.size()==0)
            return 0;
        vector<int>vi(prices.size());
        int ma=0,mb=0;
        for(int i=0;i<vi.size()-1;i++){
            vi[i]=prices[i+1]-prices[i];
        }
        for(int e:vi){
            ma=max(0,ma+e);
            mb=max(mb,ma);
        }
        return mb;
    }
    int maxProfit_2(vector<int>& prices){
        int maxprice=0;
        int minprice=1e9;
        for(int price:prices){
            maxprice=max(price-minprice,maxprice);
            minprice=min(minprice,price);
        }
        return maxprice;
    }
};
#endif 