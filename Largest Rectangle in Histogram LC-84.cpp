// tc=o(n)+o(n)
// sc=o(n)
class Solution {
public:
    int largestRectangleArea(vector<int>& in) {
        stack<int> ind;
        stack<int> h;
        int maxi=0;
        for(int i=0;i<in.size();i++){
            int indSave=i, hSave;
            while(!h.empty() && in[i]<h.top()){
                indSave=ind.top();
                hSave=h.top();
                ind.pop();
                h.pop();
                int area=(i-indSave)*hSave;
                maxi=max(maxi,area);
            }
            ind.push(indSave);
            h.push(in[i]);
        }
        while(!ind.empty()){
            int area=(in.size()-ind.top())*h.top();
            ind.pop();
            h.pop();
            maxi=max(maxi,area);
        }
        return maxi;
    }
};
// brute force
// tc=o(n^2)
// sc=o(1)
class Solution {
public:
    int largestRectangleArea(vector<int>& in) {
        int maxArea=0;
        for(int i=0;i<in.size();i++){
            int area=in[i];
            for(int j=i+1;j<in.size();j++){
                if(in[j]>=in[i]) area+=in[i];
                else break;
            }
            for(int j=i-1;j>=0;j--){
                if(in[j]>=in[i]) area+=in[i];
                else break;
            }
            maxArea=max(maxArea,area);
        }
        return maxArea;
    }
};