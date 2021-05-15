/**********INSERT ELEMENT AT END OF THE STACK WITH NO DATA STRUCTURE*********/
//Obviously, the only handy tool is RecursionCheck
//OPTIMIZED -> TC => O(N)  SC=>O(1)

stack<int> stk; //STACK HAS -> 2 3 5
void insertBot(int valToBeInsertedAtLast){
    if(stk.empty())
        stk.push(valToBeInsertedAtLast);
    else{
        char c = stk.top();                 //Won't be alternating the value to be inserted
        insertBot(valToBeInsertedAtLast); //At the return of a stack insert elemeents stored
        stk.push(c);                       //in fucntion stack  which will be as 
    }                                       //Fucntion Call stack -> 5 3 2
}                                          