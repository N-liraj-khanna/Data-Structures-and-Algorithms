// tc=o(klogk)+o((n*n)logk)
// sc=o(k)
#include <bits/stdc++.h> 
using namespace std;

vector<int> mergeKSortedArrays(vector<vector<int>>&arr, int k)
{
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
    vector<int> res;

    for(int i=0;i<k;i++){
        pq.push({arr[i][0],{i,0}});
    } 

    while(!pq.empty()){
        int val=pq.top().first;
        pair<int,int> ind=pq.top().second;
        pq.pop();

        res.push_back(val);
        if(ind.second+1<arr[ind.first].size())
            pq.push({arr[ind.first][ind.second+1], {ind.first,ind.second+1}});
    }
    return res;
}
