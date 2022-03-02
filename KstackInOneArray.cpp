/******************INSERT K STACKS IN ONE ARRAY****************/
//OPTIMIZED -> FOR all push(), pop() and peek()
//TC => O(1)  SC=>O(1)  
struct myStack{
    int size;
    int *top;
    int *arr;
    int k;
}stk;

void push(int x,int num){
    if(stk.k*num>stk.top[num]){
        stk.top[num]++;
    }
    if(stk.k*(num+1)<=stk.top[num])
        cout<<"Stack Overflow";
    else{
        stk.arr[stk.top[num]]=x;
        stk.top[num]++;
    }
}
void pop(int num){
    if(stk.k*num>stk.top[num]){
        cout<<"Stack Underflow";
    }
    if(stk.top[num]>=stk.k*(num+1)){
        stk.top[num]--;
    }
    stk.top[num]--;
}
void peek(int num){
    cout<<stk.arr[stk.top[num]];
}

int main(){
    cout<<"Size => ";
    cin>>stk.size;
    stk.arr=new int[stk.size];
    cout<<"\n K =>(less than n) ";
    cin>>stk.k;
    int div=stk.size/stk.k;
    stk.top=new int[div];
    for(int j=0,i=0;j<div;j++,i+=stk.k) stk.top[j]=i;
    int flag=1,x,stackNum,choice;
    do{
        cout<<"\n1.Push";
        cout<<"\n2.Pop";
        cout<<"\n3.Peek";
        cout<<"\n4.Quit";
        cin>>choice;
        switch(choice){
            case 1: 
                cout<<"\nX & Stack Num => ";
                cin>>x>>stackNum;
                push(x,stackNum-1);break;
            case 2: 
                cout<<"\nStack Num => ";
                cin>>stackNum;
                pop(stackNum-1);break;
            case 3: 
                cout<<"\nStack Num => ";
                cin>>stackNum;
                peek(stackNum-1);break;
            case 4: flag=0; break;
            default:break;
        }
    }while(flag==1);
}
