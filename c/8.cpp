#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

int operate(int a, int b, char op){
    if(op == '+') return a + b;
    if(op == '-') return a - b;
    if(op == '*') return a * b;
    if(op == '/') return a / b;
    return 0;
}

int evalPostfix(string expr){
    stack<int> s;
    for(char c : expr){
        if(isdigit(c)) s.push(c - '0');
        else{
            int b = s.top(); s.pop();
            int a = s.top(); s.pop();
            s.push(operate(a, b, c));
        }
    }
    return s.top();
}

int evalPrefix(string expr){
    stack<int> s;
    for(int i = expr.length() - 1; i >= 0; i--){
        char c = expr[i];
        if(isdigit(c)) s.push(c - '0');
        else{
            int a = s.top(); s.pop();
            int b = s.top(); s.pop();
            s.push(operate(a, b, c));
        }
    }
    return s.top();
}

int main(){
    string postfix = "231*+9-";
    string prefix = "-+2*319";
    cout<<evalPostfix(postfix)<<endl;
    cout<<evalPrefix(prefix)<<endl;
}




//without including inbuilt stack


/*
#include<iostream>
#include<string>
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
    int pop(){
        if(top == -1) return -1;
        return arr[top--];
    }
    bool isEmpty(){
        return top == -1;
    }
};

int operate(int a,int b,char op){
    if(op == '+') return a+b;
    if(op == '-') return a-b;
    if(op == '*') return a*b;
    if(op == '/') return a/b;
    return 0;
}

int evalPostfix(string expr){
    Stack s;
    for(int i=0;i<expr.length();i++){
        char c = expr[i];
        if(c >= '0' && c <= '9') s.push(c-'0');
        else{
            int b = s.pop();
            int a = s.pop();
            s.push(operate(a,b,c));
        }
    }
    return s.pop();
}

int evalPrefix(string expr){
    Stack s;
    for(int i=expr.length()-1;i>=0;i--){
        char c = expr[i];
        if(c >= '0' && c <= '9') s.push(c-'0');
        else{
            int a = s.pop();
            int b = s.pop();
            s.push(operate(a,b,c));
        }
    }
    return s.pop();
}

int main(){
    string postfix = "231*+9-";
    string prefix = "-+2*319";
    cout<<evalPostfix(postfix)<<endl;
    cout<<evalPrefix(prefix)<<endl;
}
*/


//8.	Write a program using stack to evaluate a prefix/postfix expression. (Inbuilt stack can be included)