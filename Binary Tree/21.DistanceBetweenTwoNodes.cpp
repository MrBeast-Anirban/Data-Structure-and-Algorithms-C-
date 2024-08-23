//Given two nodes in a Binary Tree Find the distance Between them
//By using Lowest Common Ancestor
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
//finding the level of a given node
int search(node *root, int key, int level){
    if(root == NULL){
        return -1;
    }
    if(root -> data == key){
        return level;
    }
    int left = search(root -> left, key, level+1)
    if(left != -1){
        return left;
    }
    return search(root -> right, key, level+1);
}
//function to find the distance between two nodes
int findDistance(node *root, int a, int b){
    node *lcaNode = lca(root, a, b);
    //calculate level of a and bfrom lca Node
    int levelA = search(lcaNode, a, 0);
    int levelB = search(lcaNode, b, 0);
    return levelA + levelB;
}