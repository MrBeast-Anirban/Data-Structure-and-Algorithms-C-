// BFT (Breadth First Traversal) (O(n))
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
void breadthFirstTraversal(node *root){
    queue<node *> q; //to store the address of nodes
    q.push(root);
    while(!q.empty()){
        node *f = q.front();
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

int main(){
    node *root = buildTree();
    breadthFirstTraversal(root);
    return 0; 
}
