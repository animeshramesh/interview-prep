
"""
Time: O(logN * logN)
Space: O(logN)

The idea is compare the left subtree depth with the right subtree depth.
If they are equal, we have a full tree, thus we return 2^height - 1.
If they aren't equal, we do recursive call for the root.left subtree and the root.right subtree.
Note that everytime we do recursive call for the root.left subtree or the root.right subtree,
one of them must be a full tree due to the condition of the problem.
"""

class Solution:
    def countNodes(self, root):
        leftdepth = self.getdepth(root, True)
        rightdepth = self.getdepth(root, False)

        if leftdepth == rightdepth:
            return 2 ** leftdepth - 1
        else:
            return 1 + self.countNodes(root.left) + self.countNodes(root.right)

    def getdepth(self, root, isLeft):
        if root is None:
            return 0
        if isLeft:
            return 1 + self.getdepth(root.left, isLeft)
        else:
            return 1 + self.getdepth(root.right, isLeft)


"""
Time: O(N)
"""
def countNodes(self, root):
    if root is None:
        return 0
    return 1 + self.countNodes(root.left) + self.countNodes(root.right)
