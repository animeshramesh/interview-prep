// You need to find the largest value in each row of a binary tree.

// Example:
// Input: 

//           1
//          / \
//         3   2
//        / \   \  
//       5   3   9 

// Output: [1, 3, 9]

// My solution - BFS
vector<int> largestValues(TreeNode* root) {
    vector<int> ref;
    queue<TreeNode*> q;
    if (!root) return ref;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty())
    {   int m = INT_MIN;
        while (q.front())
        {   TreeNode * node = q.front();
            q.pop();
            m = max(m, node->val);
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        q.pop();
        if (q.size() > 0) q.push(NULL);
        ref.push_back(m);
    }
    return ref;  
}