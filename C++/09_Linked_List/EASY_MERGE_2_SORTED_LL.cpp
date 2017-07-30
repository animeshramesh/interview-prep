ListNode * mergeTwoLists(ListNode *l1, ListNode* l2) {
    ListNode * newList = new ListNode(0);
    ListNode * newHead = newList;
    
    while(l1 && l2)
    {   
        if (l1->val < l2->val)
        {
            newList->next = l1;
            l1=l1->next;
        }
        else 
        {
            newList->next = l2;
            l2=l2->next;
        }

        newList=newList->next;
    }
    if(l1) newList->next=l1;  
    if(l2) newList->next=l2;
    
    return newHead->next;
}