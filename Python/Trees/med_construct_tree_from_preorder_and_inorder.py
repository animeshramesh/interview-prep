class Solution:

    def buildTree(self, preorder: List[int], inorder: List[int]):

        self.preorder = preorder
        self.inorder = inorder

        # Node value: Index in inorder traversal.
        self.val_to_index = {}
        for i, node in enumerate(inorder):
            self.val_to_index[node]= i

        # Returns the root node of the  tree.
        return self.helper(0, 0, len(inorder) - 1)


    # Our aim is to find out the index of right child for current node in the preorder array.
    # We know the index of current node in the preorder array - preStart, it's the root of a subtree.
    # Remember pre order traversal always visit all the node on left branch before going to the right ( root -> left -> ... -> right),
    # therefore, we can get the immediate right child index by skipping all the node on the left branches/subtrees of current node.
    # The inorder array has this information exactly. Remember when we found the root in "inorder" array we immediately
    # know how many nodes are on the left subtree and how many are on the right subtree.
    # Therefore the immediate right child index is preStart + numsOnLeft + 1 (remember in preorder traversal array root is always ahead of children nodes,
    # but you don't know which one is the left child which one is the right, and this is why we need inorder array)
    # numsOnLeft = root - inStart.

    # in_start and in_end are the boundaries of the inorder traversal. You can expect to find the node in that interval.
    def helper(self, pre_start, in_start, in_end):

        # Index should be within the expected boundaries.
        if pre_start > len(self.preorder) - 1 or in_start > in_end: return None

        root = TreeNode(self.preorder[pre_start])

        in_idx = self.val_to_index[root.val]
        root.left = self.helper(pre_start + 1, in_start, in_idx - 1)
        num_left_nodes = abs(in_start - in_idx) + 1
        root.right = self.helper(pre_start + num_left_nodes, in_idx + 1, in_end)

        return root
