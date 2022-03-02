#1
class Solution {
public:
    string defangIPaddr(string str) {
        string res="";
        for(int i=0;i<str.size();i++){
            if(str[i]=='.') res+="[.]";
            else res+=str[i];
        }
        return res;
    }
};

#2
class Solution {
public:
    string defangIPaddr(string str) {
        return regex_replace(str, regex("[.]"), "[.]");
    }
};