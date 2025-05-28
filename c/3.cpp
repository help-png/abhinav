#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;
    Node(int value){
        data = value;
        prev = NULL;
        next = NULL;
    }
};

class DoublyLinkedList {
private:
    Node* head;
public:
    DoublyLinkedList(){
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
        newNode->prev = temp;
    }

    void removeBeginning(){
        if(head == NULL) return;
        Node* temp = head;
        head = head->next;
        if(head != NULL) head->prev = NULL;
        delete temp;
    }

    void display(){
        Node* temp = head;
        while(temp != NULL){
            cout<<temp->data<<" <-> ";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }
};

int main(){
    DoublyLinkedList list;
    list.insertEnd(10);
    list.insertEnd(20);
    list.insertEnd(30);
    list.display();
    list.removeBeginning();
    list.display();
}

/*
3.	Write a program to implement doubly linked list that supports the following operations:
i.	Remove an element from the beginning of the doubly linked list 
ii.	Insert an element at the end of the doubly linked list
iii.	Display the elements of the list
*/