//Build a Binary Search Tree and Inset new nodes
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
//accepts the old root node and data and returns the new root node
node *insertInBST(node *root, int data){
    if(root == NULL){
        return (new node(data));
    }
    //Recursive case
    if(data <= root -> data){
        root -> left = insertInBST(root -> left, data);
    }
    else{
        root -> right = insertInBST(root -> right, data);
    }
    return root;
}
node *build(){
    //Read a list of numbers till we get first -1
    int d;
    cin >> d;
    node *root = NULL;
    while(d != -1){
        root = insertInBST(root, d);
        cin >> d;
    }
    return root;
}
//Inorder Print
void inorder(node *root){
    if(root == NULL){
        return;
    }
    inorder(root -> left);
    cout << root -> data << ", ";
    inorder(root -> right);
}
int main(){
    node *root = build();
    cout << “The inorder Traversal : “ << endl;
    inorder(root);
    return 0;
}
