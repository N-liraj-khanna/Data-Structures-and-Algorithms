// tc=o(n+n)
// sc=o(n)
class StockSpanner {
public:
    stack<pair<int,int>> stk;
    int i;
    StockSpanner() {}
    
    int next(int price) {
        if(stk.empty()){
            stk.push({price,0});
            i=1;
            return 1;
        } 
        else{
            while(!stk.empty() && stk.top().first<=price){
                stk.pop();
            }
            int t=i-(stk.empty()?(-1):stk.top().second);
            stk.push({price,i});
           i++;
           return t;
        }
    }
};


// tc=o(n^2)
// sc=o(n)
class StockSpanner {
public:
    vector<int> v;
    StockSpanner() {}
    
    int next(int price) {
        v.push_back(price);
        int count=0;
        for(int i=v.size()-1;i>=0;i--){
            if(price>=v[i]) count++;
            else break;
        }
        return count;
    }
};
