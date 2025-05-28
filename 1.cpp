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

    void insertAt(int x, int pos){
        Node* newNode = new Node(x);
        if(pos == 0){
            newNode->next = head;
            head = newNode;
            return;
        }
        Node* temp = head;
        for(int i = 0; i < pos - 1; i++){
            if(temp == NULL) return;
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void removeFromEnd(){
        if(head == NULL) return;
        if(head->next == NULL){
            delete head;
            head = NULL;
            return;
        }
        Node* temp = head;
        while(temp->next->next != NULL){
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }

    int search(int x){
        Node* temp = head;
        int index = 0;
        while(temp != NULL){
            if(temp->data == x) return index;
            temp = temp->next;
            index++;
        }
        return -1;
    }

    int countNodes(){
        int count = 0;
        Node* temp = head;
        while(temp != NULL){
            count++;
            temp = temp->next;
        }
        return count;
    }

    void display(){
        Node* temp = head;
        while(temp != NULL){
            cout<<temp->data<<" -> ";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }
};

int main(){
    LinkedList list;
    list.insertAt(10, 0);
    list.insertAt(20, 1);
    list.insertAt(30, 2);
    list.insertAt(25, 2);
    list.display();
    list.removeFromEnd();
    list.display();
    cout<<list.search(20)<<endl;
    cout<<list.search(99)<<endl;
    cout<<list.countNodes()<<endl;
}



/*
Write a program to implement singly linked list that supports the following operations:
i.	Insert an element x at ith position in the singly linked list 
ii.	Remove an element from the end of the list 
iii.	Search for an element x in the singly linked list and return its position else -1 
iv.	Count number of nodes in a given linked list.
*/