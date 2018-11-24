class Solution(object):

    def recurse(self, root):
        if not root: return 0
        if root in self.cache: return self.cache[root]

        val = 0
        if root.left is not None:
            val += self.recurse(root.left.left) + self.recurse(root.left.right)
        if root.right is not None:
            val += self.recurse(root.right.left) + self.recurse(root.right.right)
        val = max(val + root.val, self.recurse(root.left)+self.recurse(root.right))
        self.cache[root]=val
        return val

    def rob(self, root):
        self.cache = {}
        return self.recurse(root)
