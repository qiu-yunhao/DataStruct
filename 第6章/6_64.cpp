#include "Tree.cpp"
int main(){
   Tree tree;
   tree.build();
   int n = tree.getDepth(); 
   printf("%d\n",n);
   return 0;
}