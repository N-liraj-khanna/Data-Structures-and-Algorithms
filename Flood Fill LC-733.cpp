// tc=o(n)
// sc=o(h)
class Solution {
public:
    void solve(vector<vector<int>>& image, int source, int sr, int sc, int& color){
        if(sr>=image.size() || sr<0 || sc<0 || sc>=image[0].size()) return;
        
        if(image[sr][sc]==source && image[sr][sc]!=color){
            image[sr][sc]=color;
            vector<int> dir1={-1,0,1,0};
            vector<int> dir2={0,-1,0,1};
            for(int i=0;i<4;i++){
                solve(image, source, sr+dir1[i],sc+dir2[i],color);
            }
        }
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        solve(image, image[sr][sc],sr,sc,color);
        return image;
    }
};