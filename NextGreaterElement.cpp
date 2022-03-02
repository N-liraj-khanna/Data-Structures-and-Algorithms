/*******************LeetCode*****************/
/*******************496.Next Greatest Number -> 1*****************/
//OPTIMIZED -> 
//TC => O(N+(M*logN)) =>  Apprx.->O(N+M)  => Still Approx. ->O(max(N,M))
//SC=>O(N)  
class Solution {
public: 
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> map;
        stack<int> stk;
        for (int i = 0; i < nums2.size(); i++) {
            while (!stk.empty() && stk.top() < nums2[i]) {
                map[stk.top()] = nums2[i];
                stk.pop();
            }
            stk.push(nums2[i]);
        }
        for(int i=0;i<nums1.size();i++){
            if(map.find(nums1[i])==map.end()) //THIS FIND FUCNTION WILL TAKE logN TIME
                nums1[i]=-1;
            else
                nums1[i]=map[nums1[i]];
        }
        return nums1;
    }
};

 
/*******************503.Next Greatest Number -> 2*****************/
//OPTIMIZED -> TC => O(N)  SC=>O(2N)
//With a extra result/answer vector
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& a) {
        vector<int> res(a.size(), -1);
        stack<int> stk;
        for(int rep = 0; rep < 2; rep++) {
            for (int i = 0; i < a.size(); i++) {
                while (!stk.empty() && a[stk.top()] < a[i]) {
                    res[stk.top()] = a[i];
                    stk.pop();
                }
            stk.push(i);
            }
        }
    return res;
    }
};
/*******************503.Next Greatest Number -> 2*****************/
//OPTIMIZED -> TC => O(N)  SC=>O(N)
//Without any extra result/answer vector  
class Solution {
public:
    vector<long long> nextLargerElement(vector<long long> a, int n){
        stack<int> stk;
        stk.push(0);
        int i=1;
        for(i=1;i<n;i++){
            while(!stk.empty() && a[stk.top()]<a[i]){
                a[stk.top()]=a[i];
                stk.pop();
            }
            stk.push(i);
        }
        n--;
        while(!stk.empty()){
            a[stk.top()]=-1;
            stk.pop();
        }
        return a;
    }
};