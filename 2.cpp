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

class LinkedList {
private:
    Node* head;
public:
    LinkedList(){
        head = NULL;
    }

    void insertEnd(int x){
        Node* newNode = new Node(x);
        if(head == NULL){
            head = newNode;
            return;
        }
        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void removeAt(int pos){
        if(head == NULL) return;
        if(pos == 0){
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* temp = head;
        for(int i = 0; i < pos - 1; i++){
            if(temp->next == NULL) return;
            temp = temp->next;
        }
        Node* toDelete = temp->next;
        if(toDelete == NULL) return;
        temp->next = toDelete->next;
        delete toDelete;
    }

    void display(){
        Node* temp = head;
        while(temp != NULL){
            cout<<temp->data<<" -> ";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }

    void checkEvenOdd(){
        int count = 0;
        Node* temp = head;
        while(temp != NULL){
            count++;
            temp = temp->next;
        }
        if(count % 2 == 0) cout<<"Even"<<endl;
        else cout<<"Odd"<<endl;
    }
};

int main(){
    LinkedList list;
    list.insertEnd(10);
    list.insertEnd(20);
    list.insertEnd(30);
    list.insertEnd(40);
    list.display();
    list.removeAt(2);
    list.display();
    list.checkEvenOdd();
}


/*
2.	Write a program to implement singly linked list that supports the following operations:
i.	Insert an element x at the end of the list
ii.	Remove an element from ith position in the singly linked list
iii.	Display the elements of the list
iv.	Check whether the length of given linked list is even or odd.
*/