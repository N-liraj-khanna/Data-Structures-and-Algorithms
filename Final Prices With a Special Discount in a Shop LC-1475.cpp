// tc=o(n)
// sc=o(n)
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> stk;
        for(int i=prices.size()-1;i>=0;i--){
            while(!stk.empty() && prices[i]<stk.top()){
                stk.pop();
            }
            int t=prices[i];
            if(!stk.empty())
                prices[i]=prices[i]-stk.top();

            stk.push(t);
        }
        return prices;
    }
};
// tc=o(n)
// sc=o(n+n)
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> stk;
        vector<int> res(prices.size(),-1);
        for(int i=prices.size()-1;i>=0;i--){
            while(!stk.empty() && prices[i]<stk.top()){
                stk.pop();
            }
            int small=stk.empty()?prices[i]:stk.top();

            if(stk.empty())
                res[i]=small;
            else
                res[i]=prices[i]-small;
            stk.push(prices[i]);
        }
        return res;
    }
};