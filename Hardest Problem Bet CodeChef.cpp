#include<bits/stdc++.h>
using namespace std;


int main(){
    long long t;
    scanf("%lld",&t);
    for(long long i=0;i<t;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        if(c<b&&c<a){
            cout<<"Alice"<<endl;
        }else if(b<a && b<c){
            cout<<"Bob"<<endl;
        }else{
            cout<<"Draw"<<endl;
        }
    }
    return 0;
}