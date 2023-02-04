// tc=o(n*n)
// sc=o(n)
#include <bits/stdc++.h> 
using namespace std;
void sortStack(stack<int> &stk)
{
	stack<int> t;
	while(!stk.empty()){
		int x=stk.top();
		stk.pop();

		while(!t.empty() && x>t.top()){
			stk.push(t.top());
			t.pop();
		}
		t.push(x);
	}
	while(!t.empty()){
		stk.push(t.top());
		t.pop();
	}
}