/* 
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

For example, you may serialize the following tree

    1
   / \
  2   3
     / \
    4   5
as "[1,2,3,null,null,4,5]", just the same as how LeetCode OJ serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.
Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.


*/

// Preorder serialization and deserialization
class Codec 
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) 
    {
        if (root == nullptr) return "#";
        return to_string(root->val)+","+serialize(root->left)+","+serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    {
        return mydeserialize(data);
    }
    TreeNode* mydeserialize(string& data) 
    {
        if (data[0]=='#') 
        {   if (data.size() == 1) return NULL;
            data = data.substr(2);
        } 
        else 
        {
            TreeNode* node = new TreeNode(helper(data));
            node->left = mydeserialize(data);
            node->right = mydeserialize(data);
            return node;
        }
    }
private:
    // Extracts the first node from the string and removes it from the string
    // Returns the value in the node
    int helper(string& data) 
    {
        int pos = data.find(',');
        int val = stoi(data.substr(0,pos));
        data = data.substr(pos+1);  // pos + 1 to avoid the comma
        return val;
    }
};`