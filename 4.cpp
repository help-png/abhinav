#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int value){
        data = value;
        left = NULL;
        right = NULL;
    }
};

class BST {
private:
    Node* root;

    Node* insert(Node* node, int x){
        if(node == NULL) return new Node(x);
        if(x < node->data) node->left = insert(node->left, x);
        else if(x > node->data) node->right = insert(node->right, x);
        return node;
    }

    bool search(Node* node, int x){
        if(node == NULL) return false;
        if(node->data == x) return true;
        if(x < node->data) return search(node->left, x);
        else return search(node->right, x);
    }

    void inorder(Node* node){
        if(node == NULL) return;
        inorder(node->left);
        cout<<node->data<<" ";
        inorder(node->right);
    }

    void preorder(Node* node){
        if(node == NULL) return;
        cout<<node->data<<" ";
        preorder(node->left);
        preorder(node->right);
    }

    void postorder(Node* node){
        if(node == NULL) return;
        postorder(node->left);
        postorder(node->right);
        cout<<node->data<<" ";
    }

public:
    BST(){
        root = NULL;
    }

    void insert(int x){
        root = insert(root, x);
    }

    void searchElement(int x){
        if(search(root, x)) cout<<"Found"<<endl;
        else cout<<"Not Found"<<endl;
    }

    void inorderTraversal(){
        inorder(root);
        cout<<endl;
    }

    void preorderTraversal(){
        preorder(root);
        cout<<endl;
    }

    void postorderTraversal(){
        postorder(root);
        cout<<endl;
    }
};

int main(){
    BST tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);
    tree.inorderTraversal();
    tree.preorderTraversal();
    tree.postorderTraversal();
    tree.searchElement(60);
    tree.searchElement(25);
}


/*
4.	Implement Binary Search Tree as an ADT which supports the following operations:
i.	Insert an element x
ii.	Search for an element x in the BST. 
iii.	Display the elements of the BST in preorder/ inorder/ postorder traversal
*/