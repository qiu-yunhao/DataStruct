#include "Tree.cpp"
#include "vector"
void dfs(Node* node , Node* p,vector<Node*> &list,vector<vector<Node*> > &ans){
    if(node == p){
        ans.push_back(*(new vector<Node*>(list)));
        return;
    }
    if(node->left != NULL ){
        list.push_back(node);
        dfs(node->left,p,list,ans);
        list.pop_back();
    }
    if(node->right != NULL ){
        list.push_back(node);
        dfs(node->right,p,list,ans);
        list.pop_back();
    }
}

Node* findSameFather(vector<vector<Node*> > &ans1, vector<vector<Node*> > &ans2 ){
    vector<Node*> list1 = ans1[0];
    vector<Node*> list2 = ans2[0];
    for(int i = list1.size() - 1 ; i >= 0;i--){
        for(int j = list2.size() - 1 ; j >= 0 ;j--){
            if(list1[i] == list2[j]){
                return list1[1];
            }
        }
    }
    return NULL;
}

Node* getFather(Node* root,Node* p,Node *q){
    vector<Node*> v1 ,v2;
    vector<vector<Node*> > ans1 , ans2;
    dfs(root,p,v1,ans1);
    dfs(root,q,v2,ans2);
    return findSameFather(ans1,ans2);
}

int main(){
    Tree tree;
    Node *node1 = new Node;
    node1->val = 4;
    Node *node2 = new Node;
    node2->val = 5;
    Node *node3 = new Node;
    node3->val = 6;
    Node *node4 = new Node;
    node4->val = 7;
    Node *node5 = new Node;
    node5->val = 2;
    node5->left = node1;
    node5->right = node2;
    Node *node6 = new Node;
    node6->val = 3;
    node6->left = node3;
    node6->right = node4;
    Node *node7 = new Node;
    node7->val = 1;
    node7->left = node5;
    node7->right = node6;
    tree.setRoot(node7);
    Node* t = getFather(node7,node1,node2);
    if(t != NULL){
        printf("%d",t->val);
    } else{
        printf("ERROR! 空");
    }
    return 0;

}