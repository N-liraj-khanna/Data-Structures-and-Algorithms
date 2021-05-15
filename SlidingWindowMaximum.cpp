#include<iostream>
#include<queue>
#include<vector>
using namespace std;


void print(vector<int> v){
    for(int i: v){
        cout<<i<<" ";
    }
    cout<<endl;
}


    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        for (int i=0; i<nums.size(); i++) {
            if (!dq.empty() && dq.front() == i-k) dq.pop_front();
            while (!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();
            dq.push_back(i);
            if (i>=k-1) ans.push_back(nums[dq.front()]);
        }
        return ans;
    }

int main(){
    vector<int> v={1,3,-1,-3,5,3,6,};
    v=maxSlidingWindow(v,3);
    print(v);
    return 0;
}
// vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//     deque<int> dq;
//     vector<int> v;
//     int max=nums[0];
//     for(int i=0;i<k;i++){
//         if(nums[i]>max)
//             max=nums[i];
//         dq.push_back(nums[i]);
//     }
//     for(int i=k;i<nums.size();i++){

//         v.push_back(max);
//         dq.pop_front();
//         dq.push_back(nums[i]);
//         for(auto i:dq){
//             if(max<i)max=i;
//         }
//         v.push_back(max);

//     }
//     return v;
// }