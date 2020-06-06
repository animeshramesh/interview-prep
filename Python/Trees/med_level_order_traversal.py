def levelOrder(self, root: TreeNode):
    if not root: return []
    q = [[root, 0]]

    result = []
    cur_level_nodes = []
    cur_depth = 0

    while q:
        node, node_depth = q.pop(0)

        # Check if the next level has been reached.
        if node_depth > cur_depth:
            result.append(cur_level_nodes)
            cur_depth = node_depth
            cur_level_nodes = [node.val]
        else:
            cur_level_nodes.append(node.val)

        # Add children to the queue.
        if node.left:
            q.append([node.left, node_depth+1])
        if node.right:
            q.append([node.right, node_depth+1])

        # Add last level too.
        if not q and cur_level_nodes:
            result.append(cur_level_nodes)
            
    return result
