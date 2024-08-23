//Find the "Lowest Common Ancestor" of two given nodes 'a' and 'b'
node* lca(node *root, int a, int b){
    //base case
    if(root == NULL){
        return NULL;
    }
    if(root -> data == a or root -> data == b){
        return root;
    }
    //search in left and right subtree
    node *leftAns = lca(root -> left, a, b);
    node *rightAns = lca(root -> right, a, b);
    // got the lowest common ancestor
    if(leftAns != NULL and rightAns != NULL){
        return root;
    }
    //if we are getting null from right subtree but not null from left subtree then return left up
    if(leftAns != NULL){
        return leftAns;
    }
    //if we are getting null from left subtree but not null from right subtree then return right up
    return rightAns;
}
int main () {
    node* root = NULL;
    //take input the tree
    int a = 7, b = 9;
    cout << "LCA of 4 and 7 is " <<  lca(root, 4, 7) << endl;
    cout <<  "LCA of 6 and 9 is " << lca(root, 6, 9) << endl;
    return 0;
}