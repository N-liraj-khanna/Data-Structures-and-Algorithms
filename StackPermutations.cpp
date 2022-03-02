/*****************Check if an array is stack permutation of other**********************/
//OPTIMIZED -> TC => Apprx. -> O(N)  SC=>O(N)
bool isPermutation(vector<int> v1,vector<int> v2){
    stack<int> stk;
    for(int i=0;i<=v2.size();i++){
        stk.push(v1[i]);
        int j=i;
        while(!stk.empty() && v2[j]==stk.top()){
            pop();
            j--;
        }
    }
    if(!stk.empty())
        return true;
    else return false;
}
