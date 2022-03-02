#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//Naive Approach
// TC => O(N^2+logN^2)
// SC => Apprx O(2^N)
/*  int Kth largestSumArray(vector<int> v,int k){
    vector<int> vec;
    int sum=0;
    for(int i=0;i<v.size();i++){
        sum=0;
        for(int j=i;j<v.size();j++){
            sum+=v[j];
            vec.push_back(sum);
        }
    }
    sort(vec.rbegin(),vec.rend());
    return vec[k-1];
}  */

/* To find the largest Contiguous Sub Array ~and not the kth~ */
/*Kadane's Algorithm*/ 
//Most OPTIMAL!
//TC => O(N)
//SC => O(1)
//Intuition => 
/*Iterating thoughout the vector/array, by carrying max value till the ith position
and calculate the sum respectively, once the sum reaches -ve literally we have no use
of having a negative array from the start, so we can discard the sum by assgining it 
to zero, also incase if we reach a sum greater than current max value then update with 
current sum, end will give the max of sub array possible*/
//=========================HINT=================================\\
/*Literally we have no use of a sum turning negative*/
// int maxSubArray(vector<int>& nums) {
//     int maxi=nums[0],sum=nums[0];
//     for(int i=1;i<nums.size();i++){
//         if(sum<0)
//             sum=0;
//             sum+=nums[i];
//         if(sum>maxi)
//             maxi=sum;
//         }
//     return maxi;
// }

int main(){
    vector<int> v =  {10, -10, 20, -40};
    // cout<<maxSubArray(v,6);
    return 0;
}


