// tc=o(n*m)
// sc=o(1)
class Solution {
public:
    int strStr(string hay, string need) {
        if(hay.size()<need.size()) return -1;
        for(int i=0;i<hay.size();i++){
            if(hay[i]!=need[0]) continue;
            bool flag=false;
            for(int j=0, k=i;j<need.size();j++,k++){
                if(hay[k]!=need[j]){
                    flag=true;
                    break;
                }
            }
            if(!flag) return i;
        }
        return -1;
    }
};