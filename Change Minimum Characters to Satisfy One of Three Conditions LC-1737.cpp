// TC=> O(a+b+26)+O(26*(a+b)    SC=>O(26)+O(1)

class Solution {
public:
    
    int convert_string_distinct(string a, string b){
        vector<int> vec(26,0);
        
        for(auto i: a)
            vec[i-'a']++;
        
        for(auto i: b)
            vec[i-'a']++;
        
        int max=0;
        for(auto v: vec)
            if(v>max)
                max=v;
            
        return a.size()+b.size()-max;
    }
    
    int convert_strictly_less(string a, string b){
        int res=INT_MAX;
        for(int i=1;i<26;i++){
            
            int count=0;
            
            for(auto ch: a)
                if(ch-'a'>=i)
                    count++;
            
            for(auto ch: b)
                if(ch-'a'<i)
                    count++;
            
            res=min(res,count);
            
        }
        return res;
    }
    
    int minCharacters(string a, string b) {

        int distinct_res = convert_string_distinct(a, b);
        int first_is_less = convert_strictly_less(a, b);
        int second_is_less = convert_strictly_less(b, a);
        
        return min({distinct_res,first_is_less,second_is_less});
    }
};