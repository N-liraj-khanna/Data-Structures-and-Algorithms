// tc=o(n)
// sc=o(n)
#include<bits/stdc++.h>
using namespace std;
vector<int> nextSmaller(vector<int> &a)
{
    int n=a.size();
    vector<int> v(n,n);
    stack<int> s;
    s.push(n-1);
    
    for(int i=n-2;i>=0;i--)
    {
        while(!s.empty() and a[s.top()]>=a[i])
            s.pop();
        
        if(!s.empty())
            v[i]=s.top();
        s.push(i);
    }
    
    return v;
}
vector<int> prevSmaller(vector<int> &a)
{
    int n=a.size();
    vector<int> v(n,-1);
    stack<int> s;
    s.push(0);
    
    for(int i=1;i<n;i++)
    {
        while(!s.empty() and a[s.top()]>=a[i])
            s.pop();
        
        if(!s.empty())
            v[i]=s.top();
        s.push(i);
    }
    
    return v;
}
vector<int> maxMinWindow(vector<int> a, int n) {
    vector<int> ns=nextSmaller(a);
    vector<int> ps=prevSmaller(a);
    
    vector<int> ans(n,INT_MIN);
    for(int i=0;i<n;i++)
    {
        int l=(ns[i]-ps[i]-1)-1;
        if(a[i]>ans[l])
            ans[l]=a[i];
    }
    for(int i=n-2;i>=0;i--)
        if(ans[i]<ans[i+1])
            ans[i]=ans[i+1];
    return ans;
}

