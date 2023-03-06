class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int ind=2;
        vector<int> arr;
        ListNode* node=head;
        while(node->next->next){
            if(node->val > node->next->val && node->next->val < node->next->next->val){
                arr.push_back(ind);
            }else if(node->val < node->next->val && node->next->val > node->next->next->val){
                arr.push_back(ind);
            }
            node=node->next;
            ind++;
        }

        if(arr.size()<=1) return {-1,-1};
        sort(arr.begin(),arr.end());


        int mini=INT_MAX;
        for(int i=1;i<arr.size();i++){
            if(arr[i]-arr[i-1]<mini){
                mini=arr[i]-arr[i-1];
            }
        }
        return {mini,arr[arr.size()-1]-arr[0]};
    }
};