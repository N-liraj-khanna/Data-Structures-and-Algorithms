#include<bits/stdc++.h>
using namespace std;

long long func(vector<long long> &arr, long long k){
    sort(arr.begin(),arr.end());
    for(int i=0;i<k;i++)
      if(arr[i]<0)
        arr[i]*=-1;

    int sum=0;
    for(int i=0;i<arr.size();i++){
      if(arr[i]>0){
        sum+=arr[i];
      }
    }
    return sum;
}

int main(){
    long long t;
    scanf("%lld",&t);
    for(long long i=0;i<t;i++){
        long long n,k;
        scanf("%lld%lld",&n,&k);
        vector<long long> res;
        for(long long i=0;i<n;i++){
            long long in;
            scanf("%lld",&in);
            res.push_back(in);
        }
        cout<<func(res,k)<<endl;
    }
    return 0;
}