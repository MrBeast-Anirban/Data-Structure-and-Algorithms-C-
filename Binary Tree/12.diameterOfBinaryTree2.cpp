//Find the Diameter of a Binary Tree (Optimized) (O(n))
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
//or we can use pair stl
class Pair{
    public:
        int height;
        int diameter;
};
Pair fastDiameter(node *root){
    Pair p;
    if(root == NULL){
        p.diameter = p.height = 0;
        return p;
    }
    //otherwise
    Pair left = fastDiameter(root -> left);
    Pair right = fastDiameter(root -> right);

    p.height = max(left.height, right.height) + 1;
    p.diameter = max(left.height + right.height, max(left.diameter, right.diameter));
    return p;
}
int main(){
    node *root = buildTree();
    Pair p = fastDiameter(root);
    cout << "Diameter = " << p.diameter;
    return 0; 
}