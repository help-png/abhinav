#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int value){
        data = value;
        next = NULL;
    }
};

class Queue {
private:
    Node* front;
    Node* rear;
public:
    Queue(){
        front = NULL;
        rear = NULL;
    }

    void enqueue(int x){
        Node* newNode = new Node(x);
        if(rear == NULL){
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }

    void dequeue(){
        if(front == NULL) return;
        Node* temp = front;
        front = front->next;
        if(front == NULL) rear = NULL;
        delete temp;
    }

    int getFront(){
        if(front == NULL) return -1;
        return front->data;
    }

    bool isEmpty(){
        return front == NULL;
    }

    void display(){
        Node* temp = front;
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
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




//including inbuilt linked list

/*
#include <iostream>
#include <list>
using namespace std;

class Queue {
    list<int> q;
public:
    void enqueue(int x){
        q.push_back(x);
    }
    void dequeue(){
        if(!q.empty()) q.pop_front();
    }
    int getFront(){
        if(q.empty()) return -1;
        return q.front();
    }
    bool isEmpty(){
        return q.empty();
    }
    void display(){
        for(int x : q) cout << x << " ";
        cout << endl;
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
    cout << q.getFront() << endl;
    cout << q.isEmpty() << endl;
}
*/



//10.	Write a program to implement queue data structure and its operations using linked Lists. (Inbuilt Linked List can be included)