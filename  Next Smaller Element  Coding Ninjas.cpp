// tc=o(n)
// sc=o(n)
#include<bits/stdc++.h>
using namespace std;
vector<int> nextSmallerElement(vector<int> &prices, int n){
    stack<int> stk;
    for(int i=prices.size()-1;i>=0;i--){
        while(!stk.empty() && prices[i]<=stk.top()){
            stk.pop();
        }
        int cache=prices[i];
        if(!stk.empty())
            prices[i]=stk.top();
        else
            prices[i]=-1;
        stk.push(cache);
    }
    return prices;
}