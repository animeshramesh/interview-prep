void deleteNode(ListNode* node) {
    if (node)
    {
        if (node->next == NULL)
            node == NULL;
        else
        {
            while(node->next)
            {   node->val=node->next->val;
                if (node->next->next==NULL)
                    break;
                node = node->next;    
            }
            node->next = NULL;
        }
    }
}