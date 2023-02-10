// tc=o(n*n)
// sc=o(1)
int Solution::solve(string s) {
    int start=0,end=s.size()-1;
    int backup=s.size()-1, res=0;
    while(start<end){
        if(s[start]==s[end]){
            start++;
            end--;
        }else{
            start=0;
            backup--;
            end=backup;
            res++;
        }
    }
    return res;
}


// tc=o(n*n)+o(n*n)
// sc=o(n)
bool pali(string s){
    int n=s.size()-1;
    for(int i=0;i<=n/2;i++){
        if(s[i]!=s[n-i]) return false;
    }
    return true;
}
int Solution::solve(string s) {
    int max=0;
    for(int i=0;i<s.size();i++){
        if(pali(s.substr(0,i))){
            max=i;
        }
    }

    int res=0;
    string temp=s;
    for(int i=0;i<s.size();i++){
        if(pali(temp)) return res;
        res++;
        temp=s[i]+temp;
    }
    return res-max;
}
