# https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/

# Iterative Solution
# O(h) time
class Solution:

    def lowestCommonAncestor(self, root, p, q):
        while root:
            if root.val > p.val and root.val > q.val:
                root = root.left
            elif root.val < p.val and root.val < q.val:
                root = root.right
            else:
                return root
