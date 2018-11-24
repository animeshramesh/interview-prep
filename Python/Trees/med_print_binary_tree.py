"""
Print a binary tree in an m*n 2D string array following these rules:

The row number m should be equal to the height of the given binary tree.
The column number n should always be an odd number.
The root node's value (in string format) should be put in the exactly middle of the first row it can be put.
The column and the row where the root node belongs will separate the rest space into two parts
(left-bottom part and right-bottom part). You should print the left subtree in the left-bottom part and
print the right subtree in the right-bottom part. The left-bottom part and the right-bottom part should have the same size.
Even if one subtree is none while the other is not, you don't need to print anything for the none subtree
but still need to leave the space as large as that for the other subtree. However, if two subtrees are none,
then you don't need to leave space for both of them.
Each unused space should contain an empty string "".

Print the subtrees following the same rules.


Example 1:
Input:
     1
    /
   2
Output:
[["", "1", ""],
 ["2", "", ""]]


Example 2:
Input:
     1
    / \
   2   3
    \
     4
Output:
[["", "", "", "1", "", "", ""],
 ["", "2", "", "", "", "3", ""],
 ["", "", "4", "", "", "", ""]]


Example 3:
Input:
      1
     / \
    2   5
   /
  3
 /
4
Output:

[["",  "",  "", "",  "", "", "", "1", "",  "",  "",  "",  "", "", ""]
 ["",  "",  "", "2", "", "", "", "",  "",  "",  "",  "5", "", "", ""]
 ["",  "3", "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""]
 ["4", "",  "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""]]



Solution:
- You first need to get the height of the tree. (That's trivial)
- Then width of grid = 2^height - 1
- Use divide and conquer to fill in the grid
- O(h * 2^h) time and O(h * 2^h) space since the grid is of size h * (2^h-1)
"""

class Solution(object):
    def printTree(self, root):

        def get_height(node):
            if not node: return 0
            left_height = get_height(node.left)
            right_height = get_height(node.right)
            return 1 + max(left_height, right_height)

        def update_output(node, row, left, right):
            if not node: return
            mid = (left + right) / 2
            self.output[row][mid] = str(node.val)
            update_output(node.left, row + 1 , left, mid - 1)
            update_output(node.right, row + 1 , mid + 1, right)

        height = get_height(root)
        width = 2 ** height - 1
        self.output = [[''] * width for i in xrange(height)]
        update_output(node=root, row=0, left=0, right=width - 1)
        return self.output
