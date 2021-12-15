#include "6_66.cpp"

template<class T>
int getDepth(BroTree<T> &tree){
    Node_b<T>* p = tree.getRoot();
    return getNode_bDepth(p);
}

int main(){
    Tree tree;
    tree.build();
    BroTree<int> bt = exChange(tree);
    int a = getDepth(bt);
    printf("%d\n",a);
    return 0;
}