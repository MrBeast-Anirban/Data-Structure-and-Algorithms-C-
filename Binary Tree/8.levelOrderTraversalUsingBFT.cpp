// Level-Order Traversal using Breadth First Traversal (O(n))
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

int main(){
    node *root = buildTree();
    levelTraversalUsingBFT(root);
    return 0; 
}
