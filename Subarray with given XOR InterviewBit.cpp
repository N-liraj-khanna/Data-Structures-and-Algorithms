// tc=o(n)
// sc=o(n)

int Solution::solve(vector<int> &A, int B) {
    int xr=0;
    int count=0;
    unordered_map<int,int> map;
    for(int i=0;i<A.size();i++){
        xr=xr^A[i];
        int y=xr^B;
        if(y==0){
            count++;
        }
        if(map.find(y)!=map.end()){
            count+=map[y];
        }
        map[xr]++;
    }
    return count;
}
