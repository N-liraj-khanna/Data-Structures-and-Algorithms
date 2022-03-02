//My own method, sliding window reverse way(using the target variable as window)
class Solution {
public:
    string minWindow(string s, string t) {
        int N=s.size(), M=t.size();
        
        if(N<=M){
            string temp=s;
            sort(s.begin(),s.end());
            sort(t.begin(),t.end());
            if(s==t)
                return temp;
            
            return "";
            
        }
        
        unordered_map<char, int> map;  
        for(int e: t)
            map[e]++;
        
        pair<int,int> res={0,N+1}; 
        int start=0, end=0, diff=M, flag=0;
        
        
        while(end<=N){
            
            while(start<N && map.find(s[start])==map.end()){start++;}
            
            if(diff==0){
                if(res.second-res.first>end-start){
                    flag=1;
                    res={start,end};
                }
                if(map[s[start]]>=0)
                    diff++;
                map[s[start++]]++;
                
            }else if(end<N && map.find(s[end])!=map.end()){
                if(map[s[end]]>0)
                    diff--;
                map[s[end++]]--;
            }else
               end++;

        }
        
        if(flag==0)
            return "";
        return s.substr(res.first, res.second-res.first);
    }
};