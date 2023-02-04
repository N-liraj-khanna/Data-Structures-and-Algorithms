// tc=o(n)
// sc=o(1)
class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> op;
        for(int i=1,j=0;j!=target.size() && i<=n;i++){
            op.push_back("Push");
            if(j<target.size() && i==target[j]){
                j++;
            }else if(j<target.size()){
                op.push_back("Pop");
            }
        }
        return op;
    }
};