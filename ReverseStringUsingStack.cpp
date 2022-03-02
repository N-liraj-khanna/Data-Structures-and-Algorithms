/**********************String Reversal With Stack************************/
//Normal/Naive -> TC => O(N)  SC=>O(N)
char* reverse(char *S, int len)
{
    stack<char> stk;
    for(int i=0;i<len;i++){
        stk.push(S[i]);
    }
    for(int i=0;i<len;i++){
        S[i]=stk.top();
        stk.pop();
    }
    return S;
}
//Obviously Most Simple Way 
//OPTIMIZED -> TC => O(N/2)  SC=>O(1)
char* reverse(char *S, int len)
{
    for(int i=0;i<len/2;i++){
        swap(S[i],S[len-i-1]);
    }
    return S;
}