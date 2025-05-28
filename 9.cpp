#include<iostream>
using namespace std;

class Queue {
    int arr[100];
    int front, rear;
public:
    Queue(){
        front = -1;
        rear = -1;
    }
    void enqueue(int x){
        if(rear == 99) return;
        if(front == -1) front = 0;
        arr[++rear] = x;
    }
    void dequeue(){
        if(front == -1 || front > rear) return;
        front++;
        if(front > rear) front = rear = -1;
    }
    int getFront(){
        if(front == -1) return -1;
        return arr[front];
    }
    bool isEmpty(){
        return front == -1;
    }
    void display(){
        if(front == -1) return;
        for(int i = front; i <= rear; i++) cout<<arr[i]<<" ";
        cout<<endl;
    }
};

int main(){
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    q.dequeue();
    q.display();
    cout<<q.getFront()<<endl;
    cout<<q.isEmpty()<<endl;
}


//9.	Write a program to implement queue data structure and its operations using arrays