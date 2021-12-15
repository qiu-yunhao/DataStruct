#include "Tree.cpp"
#include "Stack.cpp"

void FirstSreach(Tree &tree,int *a , int *num){
    if(tree.getRoot() == NULL){
        return ;
    }else{
        Node* p = tree.getRoot();
        Stack<Node*> stack;
        stack.push(p);
        int n = *num;
        while(!stack.isEmpty()){
            Node *t = stack.pop();
            a[n++] = t->val;
            //printf("%d\n",a[n-1]);
            if(t->right != NULL){
                stack.push(t->right);
            }
            if(t->left != NULL){
                stack.push(t->left);
            }
        }
        *num = n;
    }
} 

int main(){
    Tree tree;
    tree.build();
    int n = 0;
    int *a = new int[2000];
    FirstSreach(tree,a,&n);
    printf("lalalala\n");
    printf("%d\n",n);
    for(int i = 0 ; i < n ; i++){
        printf("%d ",a[i]);
    }
    return 0;
}