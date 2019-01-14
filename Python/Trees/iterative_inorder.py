def inOrder(root):

    # Set current to root of binary tree
    current = root
    s = [] # initialze stack
    done = 0

    while(not done):

        # Reach the left most Node of the current Node
        if current:

            # Place pointer to a tree node on the stack
            # before traversing the node's left subtree
            s.append(current)

            current = current.left


        # BackTrack from the empty subtree and visit the Node
        # at the top of the stack; however, if the stack is
        # empty you are done
        else:
            if(len(s) >0 ):
                current = s.pop()
                print current.data,

                # We have visited the node and its left
                # subtree. Now, it's right subtree's turn
                current = current.right

            else:
                done = 1


def inorderTraversal(self, root):
    res, stack = [], []
    while True:
        while root:
            stack.append(root)
            root = root.left
        if not stack:
            return res
        node = stack.pop()
        res.append(node.val)
        root = node.right
