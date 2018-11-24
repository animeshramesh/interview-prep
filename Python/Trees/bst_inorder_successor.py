# Recursive
def inorderSuccessor(self, root, p):
    if not root: return None
    if root.val <= p.val:
        return inorderSuccessor(root.right, p)
    else:
        left = inorderSuccessor(root.left, p)
        if left:
            return left
        else:
            return root


def inorderSuccessor(self, root, p):
    succ = None
    while root:
        if p.val < root.val:
            succ = root
            root = root.left
        else:
            root = root.right
    return succ
