/* Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space? */

bool hasCycle(ListNode *head) {
        
    ListNode * fast = head;
    ListNode * slow = head;
    
    while (fast!=NULL && slow != NULL)
    {
        slow = slow->next;
        
        if (fast != NULL)
        {   fast = fast->next;
            if (fast != NULL)
                fast = fast->next;
        }    
        
        if (slow == fast && slow!=NULL && fast!=NULL) return true;
    }
    return false;
}