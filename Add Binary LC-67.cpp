// tc=o(n+n+n)
// sc=o(n)
class Solution {
public:
    string addBinary(string a, string b) {
        string op="";
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        if(a.size()<b.size()) swap(a,b);
        char carry='0';
        for(int i=0;i<b.size();i++){
            if(carry=='1'){
                if(a[i]!=b[i]){
                    carry='1';
                    op+='0';
                }else if(a[i]=='1'){
                    carry='1';
                    op+='1';
                }else{
                    carry='0';
                    op+='1';
                }
            }else{
                if(a[i]!=b[i]){
                    carry='0';
                    op+='1';
                }else if(a[i]=='1'){
                    carry='1';
                    op+='0';
                }else{
                    carry='0';
                    op+='0';
                }
            }
        }
        int i=b.size();
        while(i<a.size()){
            if(carry=='1' && a[i]=='1'){
                op+='0';
                carry='1';
            }else if(carry=='1' && a[i]=='0'){
                op+='1';
                carry='0';
            }else if(a[i]=='1'){
                op+='1';
            }else{
                op+='0';
            }
            i++;
        }
        if(carry=='1') op+='1';
        reverse(op.begin(),op.end());
        return op;
    }
};