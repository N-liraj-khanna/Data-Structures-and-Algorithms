// stack, if anyone knows end decrease, f anyone des increase similar to two pinter
// tc=o(n+n)
// sc=o(n)

#include <bits/stdc++.h> 
/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B); 
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

int findCelebrity(int n) {
	stack<int> stk;
	for(int i=0;i<n;i++){
		stk.push(i);
	}
	while(stk.size()>1){
		int first=stk.top();
		stk.pop();
		int second=stk.top();
		stk.pop();

		if(knows(first,second)){
			stk.push(second);
		}else{
			stk.push(first);
		}
	}

	int top=stk.top();
	for(int i=0;i<n;i++){
		if(i!=top && (knows(top,i) || !knows(i,top)))
			return -1;
	}
	return top;
}



// two pointer, if anyone knows end decrease, f anyone des increase
// tc=o(n+n)
// sc=o(1)

int findCelebrity(int n) {
	int start=0,end=n-1;
	while(start<=end){
		if(knows(start,end)) start++;
		else end--;
	}
	// cout<<end<<" "<<endl;;
	for(int i=0;i<n;i++){
		if(i!=start && (knows(start,i) || !knows(i,start))) return -1;
	}
	return start;
}

// calculate indegree and outddegree, whicher is id has ind n-1 and out 0 is celeb
// tc=(n*n)
// sc=(n)
int findCelebrity(int n) {
	vector<int> ind(n,0);
	vector<int> out(n,0);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(knows(i,j)){
				ind[j]++;
				out[i]++;
			}
		}
	}
	for(int i=0;i<n;i++){
		if(ind[i]==n-1 && out[i]==0) 
			return i;
	}
	
	return -1;
}