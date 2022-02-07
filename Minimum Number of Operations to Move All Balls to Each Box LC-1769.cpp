#1
class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> ind;
        int n=boxes.size();
        for(int i=0;i<n;i++){
            if(boxes[i]=='1') ind.push_back(i);
        }
        vector<int> res;
        for(int i=0;i<n;i++){
            int op=0;
            for(int j=0;j<ind.size();j++){
                if(i!=ind[j])
                    op+=abs(ind[j]-i);
            }
            res.push_back(op);
        }
        return res;
    }
};