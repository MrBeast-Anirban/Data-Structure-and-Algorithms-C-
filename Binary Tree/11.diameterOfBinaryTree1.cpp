//Find the Diameter of a Binary Tree
/* Diameter = length of longest path between two nodes*/
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
int height(node *root){
    if(root == NULL){
        return 0;
    }
    int heightLeft = height(root -> left);
    int heightRight = height(root -> right);
    return max(heightLeft, heightRight) + 1;
}
int diameter(node *root){
    if(root == NULL){
        return 0;
    }
    int h1 = height(root -> left);
    int h2 = height(root -> right);
    int case1 = h1 + h2;
    int case2 = diameter(root -> left);
    int case3 = diameter(root -> right);
    return max(max(case1, case2), case3);
}
int main(){
    node *root = buildTree();
    cout << "Diameter = " << diameter(root) << endl;
    return 0; 
}