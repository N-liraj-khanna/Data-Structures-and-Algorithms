// tc=o(n)
// sc=o(h)
class Solution {
public:
    void solve(vector<vector<int>>& image, int source, int sr, int sc, int& color){
        if(sr>=image.size() || sr<0 || sc<0 || sc>=image[0].size()) return;
        
        if(image[sr][sc]==source && image[sr][sc]!=color){
            image[sr][sc]=color;
            solve(image, source, sr+1,sc,color);
            solve(image, source, sr-1,sc,color);
            solve(image, source, sr,sc+1,color);
            solve(image, source, sr,sc-1,color);
        }
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        solve(image, image[sr][sc],sr,sc,color);
        return image;
    }
};