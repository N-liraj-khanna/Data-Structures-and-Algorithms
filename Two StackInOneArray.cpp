/******************TWO STACKS IN ONE ARRAY*****************/

struct myStack{
    int size;
    int *arr;
    int top1=-1,top2=size;
}stk;

//OPTIMIZED -> (from begining and end)
//push() operation -> TC => O(1)  SC=>O(1)
//pop() operation -> TC => O(1)  SC=>O(1)

void push1(int x){
    if(stk.top1>=stk.top2){
        cout<<"\nstack overflow";
    }else{
        stk.arr[++stk.top1]=x;
    }
}
void push2(int x){
    if(stk.top2<=stk.top1){
        cout<<"\nstack overflow";
    }else{
        stk.arr[--stk.top2]=x;
    }
}
void pop1(){
    if(stk.top1==-1){
        cout<<"\nstack underflow";
    }else{
        stk.top1--;
    }
}
void pop2(){
    if(stk.top1==stk.size){
        cout<<"\nstack underflow";
    }else{
        stk.top2++;
    }
}
void peek1(){
    if(stk.top1==-1){
        cout<<"\nNo Value";
    }else{
        cout<<stk.arr[stk.top1];
    }
}
void peek2(){
    if(stk.top2==stk.size){
        cout<<"\nNo Value";
    }else{
        cout<<stk.arr[stk.top2];
    }
}

int main(){
    cout<<"Enter the size of Stack"<<endl;
    int n=0;cin>>n;
    stk.size=n;
    stk.arr=new int[n];
    int flag=1,choice;
    do
    {
        cout<<"\n1.push stack 1 ";
        cout<<"\n2.push stack 2 ";
        cout<<"\n3.pop stack 1 ";
        cout<<"\n4.pop stack 2 ";
        cout<<"\n5.peek stack 1 ";
        cout<<"\n6.peek stack 2 ";
        cout<<"\n7.quit ";
        cout<<"\nYour Choice-> ";
        cin>>choice;
        int x;
        switch (choice)
        {
        case 1:
            cout<<"\nEnter val ";
            cin>>x;
            push1(x);
            break;
        case 2:
            cout<<"\nEnter val ";
            cin>>x;
            push2(x);
            break;
        case 3:
            pop1();
            break;
        case 4:
            pop2();
            break;
        case 5:
            peek1();
            break;
        case 6:
            peek2();
            break;
        case 7:
            flag=0;
            break;
        default:
        cout<<"\nEnter Valid Choice!";
            break;
        }
    } while (flag==1);
}

//Nomal/Naive Non-Efficient Way -> (Split its sizes)
//(Same complexties, but cant store more than the specified
//or allocated spcae, even if other stack has plenty of space)

//push() operation -> TC => O(1)  SC=>O(1)
//pop() operation -> TC => O(1)  SC=>O(1)

/* void push1(int x){
    if(stk.size/2==stk.top1)
        cout<<"\nStack Overflow";
    else{
        stk.top1++;
        stk.arr[stk.top1]=x;
    }
}

void push2(int x){
    if(stk.size==stk.top2)
        cout<<"\nStack Overflow";
    else{
        stk.top2++;
        stk.arr[stk.top2]=x;
    }
}

void pop1(){
    if(stk.top1==-1)
        cout<<"\nStack Underflow";
    else
        stk.top1--;
}
void pop2(){
    if(stk.top2==stk.size/2-1)
        cout<<"\nStack Underflow";
    else
        stk.top2--;
}
void peek1(){
    if(stk.top1==-1)
        cout<<"\nNo Value";
    else
        cout<<"\n"<<stk.arr[stk.top1];
}
void peek2(){
    if(stk.top2==stk.size/2-1)
        cout<<"\nNo Value";
    else
        cout<<"\n"<<stk.arr[stk.top2];
}
 */
