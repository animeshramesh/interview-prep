/* 
Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

Calling next() will return the next smallest number in the BST.

Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.


*/

class BSTIterator {
private:
    stack<TreeNode*> st;
public:
    BSTIterator(TreeNode *root) 
    {
        find_left(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() 
    {
        return !st.empty();
    }

    /** @return the next smallest number */
    int next() 
    {
        TreeNode* top = st.top();
        st.pop();
        if (top->right) find_left(top->right);
            
        return top->val;
    }
    
    /** put all the left child() of root */
    void find_left(TreeNode* root)
    {
        TreeNode* p = root;
        while (p)
        {
            st.push(p);
            p = p->left;
        }
    }
};