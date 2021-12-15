#include "Tree.cpp"
#include "Stack.cpp"

Node* copyNode(Node* p);
Tree CopyTree(Tree &tree);

int main(){
    Tree tree;
    tree.build();
    Tree p = CopyTree(tree);
    show_First(p.getRoot());
    return 0;
}


Tree CopyTree(Tree &tree){
    Node* p = tree.getRoot();
    Node* q = copyNode(p);
    Tree *t = new Tree(q);
    return *t;
}

Node* copyNode(Node *p){
    if(p == NULL){
        return NULL;
    }
    Node *t = new Node;
    t->val = p->val;
    t->left = copyNode(p->left);
    t->right = copyNode(p ->right);
    return t;
}



