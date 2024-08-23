//Given a Binary Search Tree convert it into a sorted Linked List creating a new linked List.
#include<iostream>
#include<climits>
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
//create a pair of two pointers
class LinkedList{
    public:
        node *head;
        node *tail;
};
LinkedList flattenBST(node *root){
    //will discard using left pointer from BST in building Linked List
    LinkedList l;
    if(root == NULL){
        l.head = l.tail = NULL;
    }
    //Leaf Node
    if(root -> left == NULL){
        l.head = l.tail = root;
        return l;
    }
    //Leaf is not null
    if(root -> left != NULL and root -> right == NULL){
        //convert the left subtree to Linked List
        LinkedList leftLL = flattenBST(root -> left);
        leftLL.tail -> right = root;
        l.head = leftLL.head;
        l.tail = root;
        return l;
    }
    if(root -> right != NULL and root -> left == NULL){
        //convert the right subtree to Linked List
        LinkedList rightLL = flattenBST(root -> right);
        root -> right = rightLL.head;
        l.head = root;
        l.tail = rightLL.tail;
        return l;
    }
    //Both subtree are not NULL
    LinkedList leftLL = flattenBST(root -> left);
    LinkedList rightLL = flattenBST(root -> right);
    leftLL.tail -> right = root;
    root -> right = rightLL.head;
    l.head = leftLL.head;
    l.tail = rightLL.tail;
    return l;
}
int main(){
    node *root = build();
    cout << "The inorder Traversal : " << endl;
    inorder(root);
    cout << endl << "Flattened Linked List : " << endl;
    LinkedList L = flattenBST(root);
    node *temp = L.head;
    while(temp != NULL){
        cout << temp -> data << "->";
        temp = temp -> right;
    }
    return 0;
}

