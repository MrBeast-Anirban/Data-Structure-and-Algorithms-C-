//Build a Binary Tree given InOrder and PreOrder Traversal
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
node* createTreeFromTrav(int *in, int *pre, int start, int end){
    //initialize only ones
    static int indexPre = 0; //pointer pointing to preorder array globally
    //base case
    if(start > end){
        return NULL;
    }
    //Recursive case
    node *root = new node(pre[indexPre]);
    //find the pre[indexPre] in inorder array
    int indexIn = -1;
    for(int j = start; j <= end; j++){
        if(in[j] == pre[indexPre]){
            indexIn = j;
            break;
        }
    }
    //increament index of preorder pointer
    indexPre++;
    root -> left = createTreeFromTrav(in, pre, start, indexIn-1);
    root -> right = createTreeFromTrav(in , pre, indexIn+1, end);
    return root;
}
int main(){
    int in[] = {3, 2, 8, 4, 1, 6, 7, 5};
    int pre[] = {1, 2, 3, 4, 8, 5, 6, 7};
    int n = sizeof(in)/sizeof(int);
    node *root = createTreeFromTrav(in, pre, 0, n-1);
    levelTraversalUsingBFT(root);
    return 0;
}