#include<bits/stdc++.h>
using namespace std;

void func(vector<long long> &in){
    for(long long i=1; i<in.size(); i++){
        if(in[i]<in[i-1]){
            long long q=in[i-1]/in[i];
            in[i]=q*in[i];
            if(in[i]<in[i-1]){
                in[i]+=in[i]/q;
            }
        }
    }
}

int main(){
    long long t;
    scanf("%lld",&t);
    for(long long i=0;i<t;i++){
        long long n;
        scanf("%lld",&n);
        vector<long long> res;
        for(long long i=0;i<n;i++){
            long long in;
            scanf("%lld",&in);
            res.push_back(in);
        }
        func(res);
        for(long long i: res){
            printf("%lld ",i);
        }
        printf("\n");
    }
    return 0;
}