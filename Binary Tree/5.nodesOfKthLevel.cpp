//Print all the nodes at kth level
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
int main(){
    node *root = buildTree();
    printKthLevel(root, 3);
    return 0; 
}
