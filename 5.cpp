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

class CircularLinkedList {
private:
    Node* head;
public:
    CircularLinkedList(){
        head = NULL;
    }

    void insert(int x){
        Node* newNode = new Node(x);
        if(head == NULL){
            head = newNode;
            newNode->next = head;
            return;
        }
        Node* temp = head;
        while(temp->next != head){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }

    void remove(int x){
        if(head == NULL) return;
        if(head->data == x && head->next == head){
            delete head;
            head = NULL;
            return;
        }
        Node* temp = head;
        Node* prev = NULL;
        do {
            if(temp->data == x){
                if(temp == head){
                    Node* last = head;
                    while(last->next != head){
                        last = last->next;
                    }
                    head = head->next;
                    last->next = head;
                    delete temp;
                    return;
                } else {
                    prev->next = temp->next;
                    delete temp;
                    return;
                }
            }
            prev = temp;
            temp = temp->next;
        } while(temp != head);
    }

    Node* search(int x){
        if(head == NULL) return NULL;
        Node* temp = head;
        do {
            if(temp->data == x) return temp;
            temp = temp->next;
        } while(temp != head);
        return NULL;
    }

    void display(){
        if(head == NULL) return;
        Node* temp = head;
        do {
            cout<<temp->data<<" -> ";
            temp = temp->next;
        } while(temp != head);
        cout<<"(back to head)"<<endl;
    }
};

int main(){
    CircularLinkedList list;
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.display();
    list.remove(20);
    list.display();
    Node* found = list.search(30);
    if(found != NULL) cout<<"Found: "<<found->data<<endl;
    else cout<<"Not Found"<<endl;
}


/*
5.	Write a program to implement circular linked list which supports the following operations: 
i.	Insert an element x in the list 
ii.	Remove an element from the list 
iii.	Search for an element x in the list and return its pointer
*/