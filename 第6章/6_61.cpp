#include "6_66.cpp"
#include "Stack.cpp"
template<class T>
int getChildAmount(BroTree<T> &tree){
    Node_b<T>* p = tree.getRoot();
    int m = 0; 
    Stack<Node_b<T>*> stack;
    stack.push(p);
    while (!stack.isEmpty()){
        Node_b<T>* t = stack.pop();
        if(t->son != NULL){
            stack.push(t->son);
        }
        int amount = 1;
        while(t->bro != NULL){
            amount++;
            t = t->bro;
            if(t->son != NULL){
                stack.push(t->son);
            }
        }
        m = max(m,amount);
    }
    return m;
    
}

int main(){
    Tree tree;
    tree.build();
    BroTree<int> bt = exChange(tree);
    int n = getChildAmount(bt);
    printf("%d\n",n);
    return 0;
}