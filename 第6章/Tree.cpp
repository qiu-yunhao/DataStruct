#include<iostream>
#include<string.h>
#include <cmath>
using namespace std;

struct Node{
    int val;
    Node *left;
    Node *right;
};

class Tree{
    private:
        Node *root;
    public:
        Tree(){
            root =new Node;
        }
        Tree(Node *root){
            this->root = root;
        }
        void build();
        Node* getRoot();
        void setRoot(Node* root);
        int size(Node *node);
        int getDepth();
        
        
};
void Tree::build(){
    Node *node1 = new Node;
    node1->val = 4;
    Node *node2 = new Node;
    node2->val = 5;
    Node *node3 = new Node;
    node3->val = 6;
    Node *node4 = new Node;
    node4->val = 7;
    Node *node5 = new Node;
    node5->val = 2;
    node5->left = node1;
    node5->right = node2;
    Node *node6 = new Node;
    node6->val = 3;
    node6->left = node3;
    node6->right = node4;
    Node *node7 = new Node;
    node7->val = 1;
    node7->left = node5;
    node7->right = node6;
    this->root = node7;
}

Node* Tree::getRoot(){
    return this->root;
}

void show_First(Node *node){
    if(node == NULL){
        return;
    }
    printf("%d ",node->val);
    show_First(node->left);
    show_First(node->right);
}

void show_Second(Node *node){
    if(node == NULL){
        return;
    }
    show_Second(node->left);
    printf("%d ",node->val);
    show_Second(node->right);
}

void show_Third(Node *node){
    if(node == NULL){
        return;
    }
    show_Third(node->left);
    show_Third(node ->right);
    printf("%d ",node->val);
}

void Tree::setRoot(Node *root){
    this->root = root;
}

int Tree::size(Node *node){
    if(node == NULL){
        return 0;
    }
    return size(node->left) + size(node->right) + 1;
}

int getNodeDepth(Node *node){
    if(node == NULL){
        return 0;
    }
    return max(getNodeDepth(node->left),getNodeDepth(node->right)) + 1;
}

int Tree::getDepth(){
    return getNodeDepth(this->root);
}