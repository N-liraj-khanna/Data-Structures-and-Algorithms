// tc=o(nlogn+nlogn+C*logC)
// sc=o(C)+o(C)+o(C)
vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
	priority_queue<pair<int,pair<int,int>>> pq;
	set<pair<int,int>> set;
	vector<int> res;

	sort(A.begin(),A.end(), greater<int>());
	sort(B.begin(),B.end(), greater<int>());

	pq.push({A[0]+B[0],{0,0}});
	set.insert({0,0});

	for(int a=0;a<C;a++){
		pair<int,pair<int,int>> temp=pq.top();
		pq.pop();

		res.push_back(temp.first);
		int i=temp.second.first;
		int j=temp.second.second;

		if(set.find({i+1,j})==set.end()){
			pq.push({A[i+1]+B[j],{i+1,j}});
			set.insert({i+1,j});
		}


		if(set.find({i,j+1})==set.end()){
			pq.push({A[i]+B[j+1],{i,j+1}});
			set.insert({i,j+1});
		}
	}
	return res;
}


// tc=o(n^2)*logc+clogc
// sc=o(c)
vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
	    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(int i=0;i<A.size();i++){
        for(int j=0;j<B.size();j++){
            int sum=A[i]+B[j];
            if(pq.size()==C){
                if(pq.top()<=sum){
                    pq.pop();
                    pq.push(sum);
                }
            }else{
                pq.push(sum);
            }
        }
    }
    vector<int> res;
    while(!pq.empty()){
        res.push_back(pq.top());
        pq.pop();
    }
	sort(res.begin(),res.end(), greater<int>());
    return res;
}
