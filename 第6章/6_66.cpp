#include "Tree.cpp"
#include "BrotherTree.cpp"
Node_b<int>* handle(Node* node){
    if(node == NULL){
        return NULL;
    }
    Node_b<int> *p = new Node_b<int>;
    p->val = node->val;
    p->son = handle(node->left);
    if(p->son != NULL){
        p->son->bro = handle(node->right);
    }
    return p;
}

BroTree<int> exChange(Tree &tree){
    Node_b<int> *p = handle(tree.getRoot());
    BroTree<int> bt(p);
    return bt;
}

void showFirst(Node_b<int>* node){
    if(node == NULL){
        return;
    }
    printf("%d ,",node->val);
    showFirst(node->bro);
    showFirst(node->son);
}

/*
int main(){
    Tree tree;
    tree.build();
    BroTree<int> t = exChange(tree);
    showFirst(t.getRoot());
    return 0;
}
*/

