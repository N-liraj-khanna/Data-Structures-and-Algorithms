// tc=o(n)
// sc=o(1)
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int i=num.size()-1;
        int carry=0;
        while(k || carry || i>=0){
            int temp=k%10;
            if(i>=0){
                int backup=num[i];
                num[i]=(carry+num[i]+temp)%10;
                carry=(backup+temp+carry)/10;
            }else{
                num.insert(num.begin(),(carry+temp)%10);
                carry=(carry+temp)/10;
            }
            k/=10;
            i--;
        }
        return num;
    }
};