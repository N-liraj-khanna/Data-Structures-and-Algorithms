// tc=o(n)
// sc=o(1)
class Solution {
public:
    int romanToInt(string s) {
        unordered_map <char,int> map{
            {'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        
        int i=0,n=s.size();
        int out=0;
        while(i<n){
            if(map[s[i+1]]>map[s[i]]){
                out+=(map[s[i+1]]-map[s[i]]);
                i+=2;
            }else{
                out+=map[s[i]];
                i++;
            }
        }
        return out;
}
};

// tc=o(n)
// sc=o(1)
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> map;
        map['I']=1;
        map['V']=5;
        map['X']=10;
        map['L']=50;
        map['C']=100;
        map['D']=500;
        map['M']=1000;
        
        int i=0,n=s.size();
        int out=0;
        while(i<n){
            if(i+1<n && (s[i]=='I' || s[i]=='X' || s[i]=='C') && map[s[i+1]]>map[s[i]]){
                out+=(map[s[i+1]]-map[s[i]]);
                i+=2;
            }else{
                out+=map[s[i]];
                i++;
            }
        }
        return out;
    }
};