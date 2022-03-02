
//use another string
class Solution {
public:
    string defangIPaddr(string address) {
        string ipAdd="";
        for(auto i :address){
            if(i=='.')
                ipAdd+="[.]";
            else
                ipAdd+=i;
        }
        return ipAdd;
    }
};