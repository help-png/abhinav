#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int x){
        data = x;
        next = NULL;
    }
};

class Stack {
    Node* top;
public:
    Stack(){
        top = NULL;
    }
    void push(int x){
        Node* temp = new Node(x);
        temp->next = top;
        top = temp;
    }
    void pop(){
        if(top == NULL) return;
        Node* temp = top;
        top = top->next;
        delete temp;
    }
    int peek(){
        if(top == NULL) return -1;
        return top->data;
    }
    bool isEmpty(){
        return top == NULL;
    }
    void display(){
        Node* arr[100];
        int i = 0;
        Node* temp = top;
        while(temp != NULL){
            arr[i++] = temp;
            temp = temp->next;
        }
        for(int j = i - 1; j >= 0; j--) cout << arr[j]->data << " ";
        cout << endl;
    }
};

int main(){
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();
    s.pop();
    s.display();
    cout << s.peek() << endl;
    cout << s.isEmpty() << endl;
}



//including inbuilt linked list

/*
#include<iostream>
#include<list>
using namespace std;

class Stack {
    list<int> l;
public:
    void push(int x){
        l.push_back(x);
    }
    void pop(){
        if(!l.empty()) l.pop_back();
    }
    int peek(){
        if(l.empty()) return -1;
        return l.back();
    }
    bool isEmpty(){
        return l.empty();
    }
    void display(){
        for(auto it = l.begin(); it != l.end(); it++) cout << *it << " ";
        cout << endl;
    }
};

int main(){
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();
    s.pop();
    s.display();
    cout << s.peek() << endl;
    cout << s.isEmpty() << endl;
}
*/


// 7.	Write a program to implement stack data structure and its operations using Linked List. (Inbuilt Linked List can be included)