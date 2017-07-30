// Time complexity - O(n)
// Space complexity - O(h), h = height of tree
bool isSameTree(TreeNode* p, TreeNode* q) {
        
    if (p == NULL && q == NULL) return true;
    if (p == NULL || q == NULL) return false;
    
    if (p->val != q->val) return false;
    
    bool a = isSameTree(p->left, q->left);
    bool b = isSameTree(p->right, q->right);
    return a&&b;
}