#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string _split(string s){
    string out="";
    for(int i=0;i<s.size();i++){
        if(s[i]<97){
            out+=" ";
            out+=(s[i]+32);
        }else{
            out+=s[i];
        }
    }
    return out;
}

string _combine(string s){
    string out="";
    for(int i=0;i<s.size();i++){
        if(s[i]==' '){
         i++;   
         s[i]-=32;
        }
        out+=s[i];
    }
    return out;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */     string s;
    while(getline(cin,s)){
        s.erase(remove(s.begin(), s.end(), '\r'), s.end());
        if(s[0]=='S'){
            if(s[2]=='M'){
                cout<<_split(s.substr(4,s.size()-4-2))<<endl;
            }else if(s[2]=='V'){
                cout<<_split(s.substr(4,s.size()-4))<<endl;
            }else{
                s[4]=s[4]+32;
                cout<<_split(s.substr(4,s.size()-4))<<endl;
            }
        }else if(s[0]=='C'){
            if(s[2]=='M'){
                cout<<_combine(s.substr(4,s.size()-4))<<"()"<<endl;
            }else if(s[2]=='V'){
                cout<<_combine(s.substr(4,s.size()-4))<<endl;
            }else{
                s[4]-=32;
                cout<<_combine(s.substr(4,s.size()-4))<<endl;
            }
        }
        s="";
    }
    return 0;
}
