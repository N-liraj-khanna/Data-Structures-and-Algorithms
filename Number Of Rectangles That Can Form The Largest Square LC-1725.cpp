//Best
class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& r) {
        
        int max=0, res=0;
        for(vector<int> i: r){
            int mini=min(i[0],i[1]);
            
            if(max<mini){
                max=mini;
                res=0;
            }
            if(mini==max)
                res++;
        }
        
        return res;
    }
};

//do each work individually
class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& r) {
        vector<int> sqr;
        for(auto i: r)
            sqr.push_back(min(i[0],i[1]));
        
        int max=0;
        for(auto i: sqr)
            if(max<i)
                max=i;
        
        int res=0;
        for(auto i: sqr)
            if(i==max)
                res++;
        
        return res;
    }
};