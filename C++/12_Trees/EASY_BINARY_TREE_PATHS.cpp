/* Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:

   1
 /   \
2     3
 \
  5
All root-to-leaf paths are:

["1->2->5", "1->3"]
*/

// I wasn't able to figure this out. 
// Was trying out some complex traversal techniques and wasn't sure when to append to a string and when to append a new string
// Turns out that you only need to add a new string when you reach a leaf
void binaryTreePaths(vector<string>& result, TreeNode* root, string t) {
    // t is the current path (in string)
    // Add to result if leaf node
    if(!root->left && !root->right) {
        result.push_back(t);
        return;
    }

    if(root->left) binaryTreePaths(result, root->left, t + "->" + to_string(root->left->val));
    if(root->right) binaryTreePaths(result, root->right, t + "->" + to_string(root->right->val));
}

vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> result;
    if(!root) return result;
    
    binaryTreePaths(result, root, to_string(root->val));
    return result;
}