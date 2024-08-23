//Level Order Traversal O(n*n)
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
void printKthLevel(node *root, int k){
    if(root == NULL){
        return;
    }
    if(k == 1){
        cout << root->data << ", ";
        return;
    }   
    printKthLevel(root -> left, k-1);
    printKthLevel(root -> right, k-1);
    return;
}
void levelTraversal(node *root){
    int height = heightOfTree(root);
    for(int i = 1; i <= height; i++){
        printKthLevel(root, i);
        cout << endl;
    }
}
int main(){
    node *root = buildTree();
    levelTraversal(root);
    return 0; 
}
