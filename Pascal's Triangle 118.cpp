class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> out={{1}};

        for(int j=0;j<numRows-1;j++){
            vector<int> val;
            for(int i=0;i<out[j].size();i++){
                if(i==0) val.push_back(out[j][i]);
                if(i+1<out[j].size()) val.push_back(out[j][i]+out[j][i+1]);
                if(i==out[j].size()-1) val.push_back(out[j][i]);
            }
            out.push_back(val);
        }

        return out;
    }
};