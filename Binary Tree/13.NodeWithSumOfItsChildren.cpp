//Node containing the sum of all its children nodes
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
void levelTraversalUsingBFT(node *root){
    queue<node *> q; //to store the adderss of nodes
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node *f = q.front();
        if(f == NULL){
            cout << endl;
            q.pop();
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout << f -> data << ", ";
            q.pop();
            if(f -> left){
                q.push(f -> left);
            }
            if(f -> right){
                q.push(f -> right);
            }
        }
    }
}
int childSum(node *root){
    if(root == NULL){
        return 0;
    }
    //leaf node
    if(root -> left == NULL and root -> right == NULL){
        return root -> data;
    }
    //recursive case
    int leftSum = childSum(root -> left);
    int rightSum = childSum(root -> right);
    //store current node data in temp
    int temp = root -> data;
    //update node as sum of children
    root -> data = leftSum + rightSum;
    //return the children sum + node value
    return root -> data + temp;
}
int main(){
    node *root = buildTree();
    levelTraversalUsingBFT(root);
    childSum(root);
    levelTraversalUsingBFT(root);
    return 0; 
}


