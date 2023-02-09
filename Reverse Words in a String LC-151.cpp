
// tc=o(N+N)
// sc=o(1)
class Solution {
public:
    string reverseWords(string s) {
        string res="";
        int start=s.size()-1,end;
        while(start>=0 && s[start]==' ') start--;
        end=start+1;
        
        int n=0;
        while(n<s.size() && s[n]==' ') n++;

        while(start>=n){
            if(s[start]==' '){
                res=res+s.substr(start+1,end-start-1)+" ";  
                while(start>=0 && s[start]==' ') start--;
                end=start+1;      
            }else{
                start--;
            }
        }
        if(start+1!=end)
            res+=s.substr(start+1,end-start-1);  

        return res;
    }
};

// tc=o(N+N)
// sc=o(N+n)
class Solution {
public:
    string reverseWords(string s) {
        vector<pair<int,int>> span;
        string res="";
        int start=0;
        while(start<s.size() && s[start]==' ') start++;
        int end=start;

        while(end<s.size()){
            if(s[end]==' '){
                span.push_back({start,end});
                while(end<s.size() && s[end]==' ') end++;
                start=end;
            }else{
                end++;
            }
        }
        
        if(start!=end)
            span.push_back({start,end});
        
        for(int i=span.size()-1;i>=0;i--){
            res+=s.substr(span[i].first,span[i].second-span[i].first);
            res+=" ";
        }
        res.pop_back();
        return res;
    }
};

// stack approach
// tc=o(N+N)
// sc=o(N+n)
class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        stack<string> stk;
        int start=0,end=0;
        string res="";
        while(start<n && s[start]==' ') start++;
        end=start;
        while(end<n){
            if(s[end]==' '){
                stk.push(s.substr(start,end-start));
                while(end<n && s[end]==' ') end++;
                start=end;
            }else{
                end++;
            }
        }
        if(start!=end) stk.push(s.substr(start,end-start));
        while(!stk.empty()){
            res=res+stk.top()+" ";
            stk.pop();
        }
        res.pop_back();
        return res;
    }
};