#include "Tree.cpp"
int getDepth(Node* node){
    if(node == NULL){
        return 0;
    }
    int l = getDepth(node->left);
    int r = getDepth(node->right);
    return (l > r ? l : r) + 1; 
}

void getDepth_X(Node* node,int *a,int *n,int x){
    if(node == NULL){
        return;
    }
    if(node->val == x){
        int d = getDepth(node);
        a[*n] = d;
        (*n)++;
    }
    getDepth_X(node->left,a,n,x);
    getDepth_X(node->right,a,n,x);
}

int main(){
    Tree tree;
    tree.build();
    int *a = new int[2000];
    int n = 0 ;
    getDepth_X(tree.getRoot(),a,&n,1);
    for(int i = 0 ; i < n ;i++){
        printf("%d ",a[i]);
    }
    return 0;
}