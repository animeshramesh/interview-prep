// Given a non-empty binary tree, return the average value of the nodes on each level in the form of an array.

// Optimal solution - BFS
vector<double> averageOfLevels(TreeNode* root) 
{   vector<double> res;
    if(root == NULL) return res;
    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()) 
    {
        queue<TreeNode*> temp;
        long int sum = 0, n = 0;
        while(!q.empty())
        {   n++;
            TreeNode* front = q.front();
            q.pop();
            sum+=front->val;
            if (front->left) temp.push(front->left);
            if (front->right) temp.push(front->right);

        }
        double avg = (double)sum/n;
        res.push_back(avg);
        q = temp;
    }
    
    return res;
}



// Optimal Solution - DFS
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        map<int, pair<long, int>> info;
        getLevelInfo(root, 0, info);

        vector<double> avgs(info.size());
        for (auto it = info.begin(); it != info.end(); it++) {
            long total = it->second.first;
            int nodes = it->second.second;
            avgs[it->first] = ((double)total) / nodes;
        }
        return avgs;
    }

private:
    void getLevelInfo(TreeNode* node, int l, map<int, pair<long, int>>& info) {
        if (!node) return;
        info[l].first += node->val;
        info[l].second++;
        getLevelInfo(node->left, l + 1, info);
        getLevelInfo(node->right, l + 1, info);
    }
};