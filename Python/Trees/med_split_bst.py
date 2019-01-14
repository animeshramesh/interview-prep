"""
Time: O(N)
Space: O(N)
"""
def splitBST(self, root, V):
    if not root: return [None, None]
    elif root.val<=V:
        lft, rgt = self.splitBST(root.right, V)
        root.right = lft
        return [root, rgt]
    else:
        lft, rgt = self.splitBST(root.left, V)
        root.left = rgt
        return [lft, root]
