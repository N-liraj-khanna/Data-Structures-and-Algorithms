// tc=o(n+n)
// sc=o(n+n)
class Solution {
public:
    int compareVersion(string ver1, string ver2) {
        
        vector<int> v1,v2;
        int m=ver1.size();
        int n=ver2.size();
        
        int val1=0,val2=0;
        for(int i=0;i<max(m,n);i++){
            if(i<m){
                if(ver1[i]=='.'){
                    v1.push_back(val1);
                    val1=0;
                }else{
                    val1=val1*10+(ver1[i]-'0');
                }
            }
            if(i<n){
                if(ver2[i]=='.'){
                    v2.push_back(val2);
                    val2=0;
                }else{
                    val2=val2*10+(ver2[i]-'0');
                }
            }
        }
        v1.push_back(val1);
        v2.push_back(val2);
        
        while(v1.size()<v2.size()){
            v1.push_back(0);
        }
        while(v2.size()<v1.size()){
            v2.push_back(0);
        }
        for(int i=0;i<v1.size();i++){
            if(v1[i]<v2[i]) return -1;
            if(v1[i]>v2[i]) return 1;
        }
        return 0;
    }
};