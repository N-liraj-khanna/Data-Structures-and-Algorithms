// tc=o(n^2)
// sc=o(1)
class Solution {
public:
    pair<int,int> pali(string s, int mid){
        if(mid+1>=s.size() ) return {mid,mid};
        int start=mid,end=mid;
        while(start>=0 && end<s.size() && s[start]==s[end]){
            start--;
            end++;
        }
        int fstart=start,fend=end;
        start=mid,end=mid+1;
        while(start>=0 && end<s.size() && s[start]==s[end]){
            start--;
            end++;
        }
        if((fend-fstart)>(end-start)){
            return {fstart+1,fend-1};
        }else{
            return {start+1,end-1};
        }
    }
    string longestPalindrome(string s) {
        string res="";
        int max=0;
        for(int i=0;i<s.size();i++){
            pair<int,int> temp=pali(s,i);
            if(temp.second-temp.first+1>=max){
                res=s.substr(temp.first,temp.second-temp.first+1);
                max=temp.second-temp.first+1;
            }
        }
        return res;
    }
};

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