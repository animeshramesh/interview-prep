/* 
Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the 
length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

Example:
Given a binary tree 
          1
         / \
        2   3
       / \     
      4   5    
Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].

Note: The length of path between two nodes is represented by the number of edges between them.
*/


// O(n^2) implementation
// You are computing the depth at every node
int diameterOfBinaryTree(TreeNode* root) {
    if (!root) return 0;
    int diameter = depth(root->left) + depth(root->right);
    
    int leftResult = diameterOfBinaryTree(root->left);
    int rightResult = diameterOfBinaryTree(root->right);
    
    diameter = max(diameter, max(leftResult, rightResult));
    return diameter;
}

int depth(TreeNode * node)
{   if (!node) return 0;
    return 1+max(depth(node->left), depth(node->right));
}


// O(n) implementation
// You compute the height in the same recursion
int diameterOfBinaryTree(TreeNode* root) {
    int height = 0;
    return dia(root, height);
}

int dia(TreeNode * root, int & height)
{
    if (root == NULL) return 0;
    int leftH = 0, rightH = 0;
    
    int leftDia = dia(root->left, leftH);
    int rightDia= dia(root->right, rightH);
    
    height = max(leftH, rightH) + 1;
    
    return max(leftH + rightH, max(leftDia, rightDia));
    
}