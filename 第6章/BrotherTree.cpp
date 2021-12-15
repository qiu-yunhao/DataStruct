#include <iostream>
#include <cmath>
using namespace std;

template<class T>
class Node_b{
    public:
        T val;
        Node_b<T> *son;
        Node_b<T> *bro;
};

template<class T>
class BroTree{
    private:
        Node_b<T> *root;
    public:
        BroTree();
        BroTree(Node_b<T> *root);
        void setRoot(Node_b<T> *root);
        int Leaves(Node_b<T> *node);
        Node_b<T>* getRoot();

};

template<class T>
BroTree<T>::BroTree(){
    this->root = new Node_b<T>;
}

template<class T>
BroTree<T>::BroTree(Node_b<T> *root){
    this->root = root;
}

template<class T>
Node_b<T>* BroTree<T>::getRoot(){
    return this->root;
}

template<class T>
int BroTree<T>::Leaves(Node_b<T> *node){
    if(node->son == NULL && node->bro == NULL){
        return 1;
    } else if(node->son == NULL){
        return Leaves(node -> bro);
    } else if(node ->bro == NULL){
        return Leaves(node -> son);
    } else{
        return Leaves(node->son)+Leaves(node -> bro);
    }
}

template<class T>
int getNode_bDepth(Node_b<T> *node){
    if(node == NULL){
        return 0;
    }
    return max(getNode_bDepth(node->son),getNode_bDepth(node->bro)) + 1;
}