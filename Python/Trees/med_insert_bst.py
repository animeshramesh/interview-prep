
"""
Idea is to insert in the leaf nodes (Ologn)
"""
class Solution(object):
    def insertIntoBST(self, root, val):
        if(root == None):
            return TreeNode(val);
        if(root.val < val):
            root.right = self.insertIntoBST(root.right, val);
        else:
            root.left = self.insertIntoBST(root.left, val);
        return(root)
