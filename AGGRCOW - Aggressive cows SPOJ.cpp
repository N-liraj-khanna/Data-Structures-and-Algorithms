#include <bits/stdc++.h>
using namespace std;

bool check(int mid, vector<int>& stalls, int k){
    int temp=1;
    int cow=stalls[0];
    for(int i=1;i<stalls.size();i++){
        if(stalls[i]-cow>=mid){
            cow=stalls[i];
            temp++;
        }
        if(temp==k) return true;
    }
    return false;
}
int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(),stalls.end());
    int n=stalls.size();
    int start=1,end=stalls[n-1]+stalls[0];
    while(start<=end){
        int mid=(start+end)>>1;
        if(check(mid,stalls,k)){
            start=mid+1;
        }else{
            end=mid-1;
        }
    }
    return end;
}

int main() {
  int t;
  cin>>t;
  for(int i=0;i<t;i++){
  	int N,C;
  	cin>>N;
  	cin>>C;
  	vector<int> in;
  	for(int i=0;i<N;i++){
  		int temp;
  		cin>>temp;
  		in.push_back(temp);
  	}
  	cout<<aggressiveCows(in,C)<<endl;
  }
}