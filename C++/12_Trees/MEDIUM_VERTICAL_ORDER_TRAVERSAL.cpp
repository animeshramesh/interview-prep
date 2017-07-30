/* 
Given a binary tree, return the vertical order traversal of its nodes' values. (ie, from top to bottom, column by column).

If two nodes are in the same row and column, the order should be from left to right.

Examples:
Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
 

return its vertical order traversal as:

[
  [9],
  [3,15],
  [20],
  [7]
]

*/
// BFS solution
vector<vector<int>> verticalOrder(TreeNode* root) 
{
    map<int, vector<int> > H;
    queue<pair<TreeNode*,int> > Q;
    Q.push(make_pair(root, 0));
    while(!Q.empty())
    {
        auto node = Q.front(); Q.pop();
        if(!node.first)
            continue;
        H[node.second].push_back(node.first->val);
        
        Q.push(make_pair(node.first->left,node.second-1));
        Q.push(make_pair(node.first->right,node.second+1));
    }
    
    vector<vector<int> > res;
    for(auto it : H)
        res.push_back(it.second);
    return res;
}