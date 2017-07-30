// Given a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed 
// to the original key plus sum of all keys greater than the original key in BST.


// My solution - I never leveraged the BST!! :(
class Solution {
public:
    vector<int> nums;
    
    void getNodes(TreeNode *root)
    {   if(root)
        {   nums.push_back(root->val);
            getNodes(root->left);
            getNodes(root->right);
        }
    }
    
    void convert(TreeNode *root)
    {   if (root)
        {   int curVal = root->val;
            for(int i = 0; i<nums.size(); i++)
            {   if (nums[i]>curVal)
                    root->val += nums[i];
            }
            convert(root->left);
            convert(root->right);
        }
    }
    
    TreeNode* convertBST(TreeNode* root) {
        getNodes(root);        
        convert(root);
        return root;
        
    }
};


// Optimal solution
class Solution {
public:
    int sum = 0;
    
    TreeNode* convertBST(TreeNode* root) {
        if (root) {
            convertBST(root->right);
            root->val += sum;
            sum = root->val;
            convertBST(root->left);
        }
        return root;
    }
};