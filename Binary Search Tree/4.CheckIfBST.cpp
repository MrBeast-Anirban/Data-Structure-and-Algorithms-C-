//Check If the given Binary Tree is BST or not
#include<iostream>
#include<climits>
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
bool isBST(node *root, int min = INT_MIN, int max = INT_MAX){
    if(root == NULL){
        return true;
    }
    if(root -> data >= min and root -> data <= max and isBST(root -> left, min, root -> data) and isBST(root -> right, root -> data, max)){
        return true;
    }
    return false;
}
int main(){
    node *root = build();
    cout << "The inorder Traversal : " << endl;
    inorder(root);
    isBST(root) ? cout << endl << "BST" : cout << endl << "Not BST";
    return 0;
}
