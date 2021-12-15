#include "Tree.cpp"
#include "Stack.cpp"

void behindSearch(int *a,int *n,Tree &tree){
    if(tree.getRoot() == NULL){
        return;
    }
    int m = *n;
    Node *p = tree.getRoot();
    Stack<Node*> stack;
    Node *q = NULL;
    while(!stack.isEmpty() || p != NULL){
        while(p != NULL){
            stack.push(p);
            p = p->left;
        }   
        p = stack.pop();
        if(p->right != NULL && p->right != q){
            stack.push(p);
            p = p->right;
        }else{
            a[m++] = p->val;
            q = p;
            p = NULL;
        }
    }
    *n = m;

}

int main(){
    Tree tree;
    tree.build();
    int *a = new int[2000];
    int n = 0;
    behindSearch(a,&n,tree);
    for(int i = 0 ; i < n; i++){
        printf("%d ",a[i]);
    }
    return 0;
}