// Normal greedy approach without recursion
class Solution {
public:
    bool check(string word1, string word2, int i, int j){
        while(i<word1.size() && j<word2.size()){
            if(word1[i]>word2[j])
                return true;
            else if(word1[i]<word2[j])
                return false;
            i++;j++;
        }
        if(i==word1.size())
            return false;
        else
            return true;
    }
    string largestMerge(string word1, string word2) {
        string merge="";
        int N=word1.size(),M=word2.size();
        int i,j,t,p;
        
        for(i=0, j=0;i<N && j<M;){
            if(word1[i]>word2[j]){
                merge+=word1[i];
                i++;
            }else if(word1[i]<word2[j]){
                merge+=word2[j];
                j++;
            }else if(word1[i]==word2[j]){
                
                if(check(word1, word2,i+1,j+1)){
                    merge+=word1[i++];
                }else{
                    merge+=word2[j++];
                }
            }
        }
                
        merge+=word1.substr(i,N);
        merge+=word2.substr(j,M);        
        return merge;
    }
};

// using simple recursion, take each char on each call
class Solution {
public:
    string largestMerge(string word1, string word2) {
        if(!word1.size() || !word2.size())
            return word1+word2;
        
        if(word1>word2)
            return word1[0]+largestMerge(word1.substr(1),word2);
        
        return word2[0]+largestMerge(word1,word2.substr(1));
    }
};