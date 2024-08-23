//Build a Binary Tree using recursion
#include<iostream>
using namespace std;
class node{
    public:
        int data;
        node *left;
        node *right;
        node(int d){
            data = d;
            left = NULL;
            right = NULL;
        }
};
node *buildTree(){
    int d;
    cin >> d;
    //if the user want the node to be NULL
    if(d == -1){
        return NULL;
    }
    node *root = new node(d);
    root -> left = buildTree();
    root -> right = buildTree();
    return root;
}
void preorderTraversal(node *root){
    //Preorder Traversal
    if(root == NULL){
        return;
    }
    //otherwise print root first then left and right
    cout << root -> data << ", ";
    preorderTraversal(root -> left);
    preorderTraversal(root -> right);
}
int main(){
    node *root = buildTree();
    preorderTraversal(root);
    return 0; 
}
