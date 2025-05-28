#include<iostream>
using namespace std;

class Stack {
    int arr[100];
    int top;
public:
    Stack(){
        top = -1;
    }
    void push(int x){
        if(top == 99) return;
        arr[++top] = x;
    }
    void pop(){
        if(top == -1) return;
        top--;
    }
    int peek(){
        if(top == -1) return -1;
        return arr[top];
    }
    bool isEmpty(){
        return top == -1;
    }
    void display(){
        for(int i = 0; i <= top; i++) cout << arr[i] << " ";
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


/*
6.	Write a program to implement stack data structure and its operations using arrays.
*/