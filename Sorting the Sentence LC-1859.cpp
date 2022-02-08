//Use map in order to store each word alone wihtout the number itself
//TC => O(N) SC => O(1)
class Solution {
public:
    string sortSentence(string s) {
        unordered_map<int, string> m;
        int j = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= 48 && s[i] <= 57) {
                m[s[i]-'0'] = s.substr(j, i-j);
                j = i + 2;
            }
        }
        string res = "";
        for (int i = 1;i<=m.size();i++) {
            res += m[i];
            res += " ";
        }
        res.pop_back();
        return res;
    }
};

// 2
class Solution {
public:
    string sortSentence(string s) {
        
        unordered_map<int, string> m;
        int strt=0;
        string res="";
        
        for(int i=0;i<s.size();i++){
            if(s[i]>='1' && s[i]<='9'){
                m[s[i]-'0']=s.substr(strt, i-strt);
            }
            if(s[i]==' ') strt=i+1;
        }

        for(int i=1;i<m.size();i++){
            res+=m[i]+" ";
        }
        res+=m[m.size()];
        return res;
    }
};