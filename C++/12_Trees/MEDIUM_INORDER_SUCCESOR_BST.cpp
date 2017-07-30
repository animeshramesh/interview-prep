/* Given a binary search tree and a node in it, find the in-order successor of that node in the BST.

Note: If the given node has no in-order successor in the tree, return null.
*/

/* 
1) If right subtree of node is not NULL, then succ lies in the leftmost leaf of right subtree. 
2) If right subtree of node is NULL, then start from root and search.
Travel down the tree, if node’s data is greater than root’s data then go right side, otherwise go to left side.
*/

// Time complexity - O(h), h = height of tree
// http://www.geeksforgeeks.org/tree-traversals-inorder-preorder-and-postorder/
// Edge cases - consider cases of leaves
Node * inOrderSuccessor(Node *root, Node *n)
{
    // step 1 of the above algorithm
    if( n->right)
        return minValue(n->right);
 
    Node *succ = NULL;
 
    // Start from root and search for successor down the tree
    while (root)
    {
        if (n->data < root->data)
        {   succ = root;
            root = root->left;
        }
        else if (n->data > root->data)
            root = root->right;
        else
           break;
    }
 
    return succ;
}

Node * minValue(Node * node) {
  Node* current = node;
  
  /* loop down to find the leftmost leaf */
  while (current->left) 
    current = current->left;
  return current;
}