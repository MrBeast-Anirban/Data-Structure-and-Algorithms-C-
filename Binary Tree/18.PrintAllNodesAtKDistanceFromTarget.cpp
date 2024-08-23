//Print all nodes that are at k distance from given target node
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
//function to print all nodes that are at k level from a target node
void printAtLevelK(node *root, int k){
    if(root == NULL){
        return;
    }
    if(k == 0){
        cout << root -> data << ", ";
        return;
    }
    printAtLevelK(root -> left, k-1);
    printAtLevelK(root -> right, k-1);
    return;
}
int printAtDistanceK(node *root, node *target, int k){
    //target node is not present
    if(root == NULL){
        return -1;
    }
    //reached the target node
    if(root == target){
        printAtLevelK(target, k);
        //return distance from target node
        return 0;
    }
    //the below steps are happenning when control is returning after  finding the target node control will return via its ancestors.
    //check for the ancestor nodes (target is at left)
    int DL = printAtDistanceK(root -> left, target, k);
    if(DL != -1){
        //Again there are 2 cases
        //Case 1 :- Ancestor itself need to be printed
        if(DL + 1 == k){
            cout << root -> data << ", ";
        }
        //Case 2 :- call at the right subtree of ancestor
        else{
            printAtLevelK(root -> right, k-2-DL);
        }
        //return distance to the parent
        return 1+DL;
    }
    //check for ancestor nodes (target is at right)
    int DR = printAtDistanceK(root -> right, target, k);
    if(DR != -1){
        if(DR+1 == k){
            cout << root -> data << ", ";
        }
        else{
            printAtLevelK(root -> left, k-2-DR);
        }
        return 1+DR;
    }
    //Node was not present left and right subtree of given node
    return -1;
}
int main(){
    node *root = NULL;
    //build Tree
    node *target = root -> left -> left;
    printAtDistanceK(root, target, 2);
    return 0;
}