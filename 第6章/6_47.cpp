#include "Tree.cpp"
#include "Queue.cpp"
void Cengxv(Tree &tree,int* a,int* n){
    Node* p = tree.getRoot();
    if(p == NULL){
        return;
    }
    Queue<Node*> queue;
    queue.offer(p);
    int m = *n;
    while(!queue.isEmpty()){
        Node *t = queue.poll();
        a[m++] = t->val;
        if(t->left != NULL){
            queue.offer(t->left);
        }
        if(t->right != NULL){
            queue.offer(t->right);
        }
    }
    *n = m;
}

int main(){
    Tree tree;
    tree.build();
    int *a = new int[200];
    int n = 0;
    Cengxv(tree,a,&n);
    for(int i = 0 ; i < n ; i++){
        printf("%d ",a[i]);
    }
    return 0;
}