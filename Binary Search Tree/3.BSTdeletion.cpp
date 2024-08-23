//Deletion in Binary Search Tree
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
//accepts the old root node and data and returns the new root node
node *insertInBST(node *root, int data){
    if(root == NULL){
        return (new node(data));
    }
    //Recursive case
    if(data <= root -> data){
        root -> left = insertInBST(root -> left, data);
    }
    else{
        root -> right = insertInBST(root -> right, data);
    }
    return root;
}
node *build(){
    //Read a list of numbers till we get first -1
    int d;
    cin >> d;
    node *root = NULL;
    while(d != -1){
        root = insertInBST(root, d);
        cin >> d;
    }
    return root;
}
//Inorder Print
void inorder(node *root){
    if(root == NULL){
        return;
    }
    inorder(root -> left);
    cout << root -> data << ", ";
    inorder(root -> right);
}
node *deleteInBST(node *root, int key){
    if(root == NULL){
        return NULL;
    }
    else if(key < root -> data){
        root -> left = deleteInBST(root -> left, key);
        return root;
    }
    else if(root -> data == key){
        //Found the data to delete (3 cases)
        //Case1. Node with 0 children (Leaf Node)
        if(root -> left == NULL and root -> right == NULL){
            delete root;
            return NULL;
        }
        //Case2. Node with only 1 child
        if(root -> left != NULL and root -> right == NULL){
            node *temp = root -> left;
            delete root;
            return temp;
        }
        if(root -> left == NULL and root -> right != NULL){
            node *temp = root -> right;
            delete root;
            return temp;
        }
        //Case3. Node with 2 children  (Inorder Successor)
        node *replace = root -> right;
        while(replace -> left != NULL){
            replace = replace -> left;
        }
        root -> data = replace -> data;
        //delete the replace node
        root -> right = deleteInBST(root -> right, replace -> data);
        return root;
    }
    else{
        root -> right = deleteInBST(root -> right, key);
        return root;
    }
}
int main(){
    node *root = build();
    cout << "The inorder Traversal : " << endl;
    inorder(root);
    cout << endl << "Enter Element You want to delete : ";
    int s; 
    cin >> s;
    root = deleteInBST(root, s);
    inorder(root);
    return 0;
}
