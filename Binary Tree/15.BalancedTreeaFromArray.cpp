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

node* buildTreeFromArray(int *a, int start, int end){
    //base case
    if(start > end){
        return NULL;
    }
    //recursive case
    int mid = (start + end)/2;
    node *root = new node(a[mid]);
    root -> left = buildTreeFromArray(a, start, mid-1);
    root -> right = buildTreeFromArray(a, mid+1, end);
    return root;
}
int main(){
    int a[] = {1, 2, 3, 4, 5, 6, 7};
    int n = 7;
    node *root = buildTreeFromArray(a, 0, n-1);
    levelTraversalUsingBFT(root);
    return 0; 
}
