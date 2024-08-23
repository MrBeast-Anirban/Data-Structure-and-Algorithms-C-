//Postorder Traversal
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
void inorderTraversal(node *root){
    if(root == NULL){
        return;
    }
    inorderTraversal(root -> left);
    cout << root -> data << ", ";
    inorderTraversal(root -> right);
}
void postorderTraversal(node *root){
    if(root == NULL){
        return;
    }
    postorderTraversal(root -> left);
    postorderTraversal(root -> right);
    cout << root -> data << ", ";
}

int main(){
    node *root = buildTree();
    postorderTraversal(root);
    return 0; 
}
