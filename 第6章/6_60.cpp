#include "6_66.cpp"

int main(){
    Tree tree;
    tree.build();
    BroTree<int> bt = exChange(tree);
    int n = bt.Leaves(bt.getRoot());
    printf("%d\n",n);
    return 0;
}