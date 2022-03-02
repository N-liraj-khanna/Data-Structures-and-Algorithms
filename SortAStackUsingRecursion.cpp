/*****************SORT STACK USING RECURSION**************/
/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */
//OPTIMIZED -> TC => O(N^2)  SC=>O(1)
void insert(stack<int>& s, int val){
    if(s.empty()) s.push(val);
    else if(s.top()<val) s.push(val);
    else{
        int topVal = s.top();
        s.pop();
        insert(s,val);
        s.push(topVal);
    }
}

void SortedStack :: sort()
{
    if(s.empty()) return;
   int val = s.top();
   s.pop();
   sort();
   insert(s,val);
}