// Brute force
// TC => 0(NlogN)+O(N)
// SC=>O(N)

class Solution {
public:

    vector<vector<int>> merge(vector<vector<int>>& in) {
        if(in.size()<=1) return in;

        sort(in.begin(),in.end());
        vector<vector<int>> out={in[0]};

        for(int i=1, j=0;i<in.size();i++){
            if(out[j][1]>=in[i][0]){
                out[j][1]=max(in[i][1],out[j][1]);
            }else{
                out.push_back({in[i][0],in[i][1]});
                j++;
            }
        }
        return out;
    }
};