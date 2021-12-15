#include "Tree.cpp"

void exChange(Node* node){
    if(node == NULL){
        return;
    }else{
        Node *l = node->left;
        Node *r = node->right;
        node->left = r;
        node->right = l;
        exChange(node->left);
        exChange(node->right);
    }
}

int main(){
    Tree tree;
    tree.build();
    exChange(tree.getRoot());
    show_First(tree.getRoot());
    return 0;
}