class Solution {
public:
    int countVowelStrings(int n) {
        vector<int> count(5,1);
        
        for(int i=2;i<=n;i++){
            for(int j=3;j>=0;j--){
                count[j]+=count[j+1];
            }
        }
        int sum=0;
        for(int i: count)
            sum+=i;
        return sum;
    }
};