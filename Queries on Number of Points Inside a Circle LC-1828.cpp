#1 Decent understandable
class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& v, vector<vector<int>>& q) {
        vector<int> res(q.size(), 0);
        for(int i=0;i<q.size();i++){
            int x1=q[i][0], y1=q[i][1], r=q[i][2];
            
            for(int j=0;j<v.size();j++){
                int x2=v[j][0], y2=v[j][1];
                
                if( pow( (x1-x2), 2)+pow( (y1-y2), 2) <= r*r )
                    res[i]++;
            }
        }
        return res;
    }
};

#2 Crazy
class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& v, vector<vector<int>>& q) {
        vector<int> res(q.size(), 0);
        for(int i=0;i<q.size();i++){            
            for(int j=0;j<v.size();j++){                
                res[i]+=pow( (q[i][0]-v[j][0]), 2)+pow( (q[i][1]-v[j][1]), 2) <= q[i][2]*q[i][2];
            }
        }
        return res;
    }
};