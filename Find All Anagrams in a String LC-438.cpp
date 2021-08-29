class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> map;
        vector<int> res;
        
        int N=s.size(), M=p.size();
        int start=0, end=0, diff=M;
        
        for(int i=0;i<M;i++){
            map[p[i]]++;
        }    
        
        while(end<N){
            if(map.find(s[end])!=map.end()){
                map[s[end]]--;
                if(map[s[end]]>=0)
                    diff--;
            }
            end++;
            
            if(diff==0){
                res.push_back(start);
            }
            
            if(end-start==M){
                if(map.find(s[start])!=map.end()){
                    if(map[s[start]]>=0)
                        diff++;
                    map[s[start]]++;
                }
                start++;
            }   
        }
        
        return res;
    }
};