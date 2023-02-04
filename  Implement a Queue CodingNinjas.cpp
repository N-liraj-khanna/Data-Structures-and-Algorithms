#include <bits/stdc++.h> 
using namespace std;
class Queue {
public:
    int *q = new int[5001];
    int rear=-1;
    int back=-1;
    Queue() {}

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        return back==rear;
    }

    void enqueue(int data) {
        back++;
        q[back]=data;
    }

    int dequeue() {
        if(rear==back) return -1;
        rear++;
        int x=q[rear];
        return x;
    }

    int front() {
        if(rear==back) return -1;
        return q[rear+1];
    }
};
