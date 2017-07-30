/* Given a binary search tree (BST) with duplicates, find all the mode(s) (the most frequently occurred element) in the given BST.

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than or equal to the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.
For example:
Given BST [1,null,2,2],
   1
    \
     2
    /
   2
return [2].

Note: If a tree has more than one mode, you can return them in any order.

Follow up: Could you do that without using any extra space? (Assume that the implicit stack space incurred due to recursion does not count).
*/

/*
Key Observation: Obviously, it is very easy to get modes from a sorted array since all duplicates are consecutive.

An in-order traversal of BST gives exactly a sorted sequence.

Naturally, in-order traversal takes O(N) time. To achieve O(1) extra space, we cannot store the array of in-order node values. 
But all modes can be found in two traversals:

Find max frequency of node values mfq by counting and update number of duplicates.
Store a mode into result vector<int> modes whenever the duplicates match mfq from first traversal.
Note: we can accomplish both traversals by keeping 2 variables pre (previous node value) and cnt (count of current duplicates):

Update cnt by ++(cnt*=(r->val==pre)), i.e., r->val==pre? ++cnt : cnt=1;
Update pre by simply copying pre = r->val;
*/

vector<int> modes;

vector<int> findMode(TreeNode* r) {
  int mfq/*max freq*/, pre/*previous val*/, cnt/*duplicates count*/;
  getMaxFreq(r, mfq=0, pre, cnt=0); // in-order traversal to get max frequency
  getMode(r, mfq, pre, cnt=0);      // in-order traversal to get all modes
  return modes;
}

void getMaxFreq(TreeNode* r, int& mfq, int& pre, int& cnt) {
  if (!r) return;
  getMaxFreq(r->left, mfq, pre, cnt);
  getMaxFreq(r->right, mfq=max(mfq,cnt), pre=r->val, ++(cnt*=(r->val==pre)));
}

void getMode(TreeNode* r, const int mfq, int& pre, int& cnt) {
  if (!r) return;
  getMode(r->left, mfq, pre, cnt);
  if (mfq == ++(cnt*=(r->val==pre))) modes.push_back(r->val);
  getMode(r->right, mfq, pre=r->val, cnt);
}

// Another solution
vector<int> findMode(TreeNode* root) {
    unordered_map<int,int> counts;
    int max = 0;
    utill(root, counts, max);
    
    vector<int> modes;
    for(auto& y : counts){
        if(y.second == max) modes.push_back(y.first);
    }
    return modes;
}

void utill(TreeNode* r, unordered_map<int,int> &counts, int &max){
    if(r == nullptr) return;
    
    ++counts[r->val];
    max = std::max(max, counts[r->val]);
    utill(r->left, counts, max);
    utill(r->right, counts, max);
}