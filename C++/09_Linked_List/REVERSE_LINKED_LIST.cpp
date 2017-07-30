// My solution - Use a stack to store numbers
ListNode*getNewNode(int x)
{
    ListNode * a = new ListNode(x);
    a->val=x;
    a->next = NULL;
    return a;
}
ListNode* reverseList(ListNode* head) {
    
    ListNode* reversed = new ListNode(0);
    stack<int> ref;
    while(head != NULL)
    {
        ref.push(head->val);
        cout << "Pushing " << head->val << endl;
        head = head->next;
    }
    ListNode* head1 = reversed;
    while(!ref.empty())
    {   
        ListNode * node = new ListNode(ref.top());
        cout << "Popping " << ref.top() << endl;
        ref.pop();
        reversed->next = node;
        reversed = node;
    }
    return head1->next;
}

// Optimal solution
ListNode * reverseList(ListNode * head) {
    ListNode * prev = null;
    ListNode * curr = head;
    while (curr != null) {
        ListNode * nextTemp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextTemp;
    }
    return prev;
}