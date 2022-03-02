#include<bits/stdc++.h>
using namespace std;


int main(){
    long long t;
    scanf("%lld",&t);
    for(long long i=0;i<t;i++){
        int n,k,s;
        cin>>n>>k>>s;
        int odd=1,sum=0;
        for(int i=0;i<n;i++){
          sum+=odd;
          odd+=2;
        }
        cout<<(s-sum)/(k-1)<<endl;
    }
    return 0;
}