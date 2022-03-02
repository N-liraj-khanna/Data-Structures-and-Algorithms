/***********Special Stack With All Operations and Find middle element***********/
 /******************************of stack in O(1)*******************************/ 

//Doubly Linked List is the best way of implementing O(1)

#include<iostream>
using namespace std;

struct mySTACK {
    int size;
    int count = 0;
    DLL* topLink = new DLL;
    DLL* midLink=topLink;
}stk;

//OPTIMIZED -> 
//push() operation -> TC => O(1)  SC=>O(1)
//pop() operation -> TC => O(1)  SC=>O(1)
//peek() operation -> TC => O(1)  SC=>O(1)
//middleDelete() operation -> TC => O(1)  SC=>O(1)
//middlePeek() operation -> TC => O(1)  SC=>O(1)

void push(int x) {
    if (stk.count >= stk.size)
        cout << "\nStack Overflow";
    else {
        DLL* temp = stk.topLink;
        stk.topLink->nextLink = new DLL;
        stk.topLink = stk.topLink->nextLink;
        stk.topLink->prevLink = temp;
        stk.topLink->myVal = x;
        stk.count++;
        if (stk.count%2==0)
            stk.midLink = stk.midLink->nextLink;
    }
}

void pop() {
    if (stk.count == 0)
        cout << "\nStack Underflow";
    else {
        stk.count--;
        stk.topLink=stk.topLink->prevLink;
        delete(stk.topLink->nextLink);
        stk.topLink->nextLink = NULL;
        if (stk.count % 2 == 0)
            stk.midLink = stk.midLink->prevLink;
    }
}

void peek() {
    if (stk.count == 0) cout << "\nNo Value";
    else cout << stk.topLink->myVal;
}

void deleteMiddle() {
    if (stk.count == 0)
        cout << "Stack Underflow";
    else {
        DLL* temp = stk.midLink->nextLink;
        stk.midLink = stk.midLink->nextLink->nextLink;
        delete(temp);
        stk.count--;
    }
}

void peekMiddle() {
    if (stk.count == 0)
        cout << "\nNo Value";
    else {
        cout << stk.midLink->nextLink->myVal;
    }
}
int main(){
    cout<<"Enter the size of Stack"<<endl;
    int n=0;cin>>n;
    stk.size=n;
    cout<<"\nEnter k, (less than n) ";
    int k;cin>>k;
    int flag=1,choice;
    do{
        cout<<"\n1.Push ";
        cout<<"\n2.Pop ";
        cout<<"\n3.Peek ";
        cin>>choice;
        int x,stackNum;
        switch (choice)
        {
        case 1:
        cout<<"\nEnter val and stack Number ";
        cin>>x>>stackNum;
            push(x,stackNum);
            break;
        case 2:
        cout<<"\nEnter stack Number ";
        cin>>stackNum;
            pop(stackNum);
            break;
        case 3:
            cout<<"\nEnter stack Number ";
            cin>>stackNum;
            peek(stackNum);
        case 4:
            flag=0;
        default:
            break;
        }
    }while(flag==1);

}