/* 
Invert a binary tree.

     4
   /   \
  2     7
 / \   / \
1   3 6   9
to
     4
   /   \
  7     2
 / \   / \
9   6 3   1

*/

// Time complexity - O(n)
// Space complexity - O(h), h = height of tree
TreeNode* invertTree(TreeNode* root) {
    if (root)
    {
        swap(root->left, root->right);
        root->left = invertTree(root->left);
        root->right = invertTree(root->right);
        return root;
    }
    return NULL;
}