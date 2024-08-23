//Find the sum of all nodes in Binary Tree
#include<iostream>
#include<queue>
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
int sumOfNodes(node *root){
    if(root == NULL){
        return 0;
    }
    return (root -> data + countNodes(root -> left) + countNodes(root -> right));
}
int main(){
    node *root = buildTree();
    sumOfNodes(root);
    return 0; 
}
