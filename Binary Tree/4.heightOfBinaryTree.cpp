//Find the Height of the Binary Tree
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
int heightOfTree(node *root){
    if(root == NULL){
        return 0;
    }
    int heightLeft = heightOfTree(root -> left);
    int heightRight = heightOfTree(root -> right);
    return max(heightLeft, heightRight) + 1;
}

int main(){
    node *root = buildTree();
    heightOfTree(root);
    return 0; 
}
