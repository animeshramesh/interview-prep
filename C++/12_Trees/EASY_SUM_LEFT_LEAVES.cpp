/* Find the sum of all left leaves in a given binary tree.

Example:

    3
   / \
  9  20
    /  \
   15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24. */

// Time complexity - O(n)
// Space complecity - O(h)
int getSum(TreeNode * root)
{   
    if (!root) return 0;
    int sum=0;

    // If there's a left node and that left node is a leaf
    if (root->left && !root->left->left && !root->left->right)
        sum+= root->left->val;
    
    // Else, just go left
    else sum+=getSum(root->left);

    sum+=getSum(root->right);
    return sum;    

}

int sumOfLeftLeaves(TreeNode* root) {
    
    return getSum(root);
    
}