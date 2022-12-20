// Power set Algorithm
// Bit manipulation
// TC=> O(2^n)*O(N) 
// SC => O(1)

#include<iostream>
#include<vector>
using namespace std;

int main(){
  int n;
  cin>>n;
  vector<int> in;
  for(int i=0;i<n;i++){
    int a;
    cin>>a;
    in.push_back(a);
  }

for(int i=0;i<=(1<<n)-1;i++){
  int sum=0;
  for(int j=0;j<n;j++){
    if((i&(1<<j))!=0){
      sum-=in[j];
    }else{
      sum+=in[j];
    }
  }
  if(sum%360==0){
    cout<<"YES";
    return 0;
  } 
}
  cout<<"NO";
  return 0;
} 