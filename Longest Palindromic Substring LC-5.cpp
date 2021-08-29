//using big table to keep track of all
class Solution {
public:
    string longestPalindrome(string s) {
        int N=s.size(),i,j;
        vector<vector<bool>> track(N, vector<bool>(N));
        for(i=0;i<N-1;i++){
            track[i][i]=1;
            if(s[i]==s[i+1])
                track[i][i+1]=1;
        }
        track[i][i]=1;
        
        for(int i=2;i<N;i++){
            for(int j=0,k=i;k<N;j++, k++){
                if(s[j]==s[k] && track[j+1][k-1]==1){
                    track[j][k]=1;
                }
            }
        }
        
        pair<int,int> res={0,0};
        for(int i=0;i<N;i++){
            for(int j=i+1;j<N;j++){
                if(track[i][j]==1 && res.second-res.first<j-i){
                    res={i,j};  
                }
            }
        }
        
        return s.substr(res.first, res.second-res.first+1);
    }
};