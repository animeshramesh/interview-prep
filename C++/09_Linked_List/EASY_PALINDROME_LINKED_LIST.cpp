/* Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space? */

// Basic idea is to find the middle of the LL using 2 pointers.. Slow and fast.
// Then reverse the 2nd half the LL and compare it with the 1st half.

bool isPalindrome(ListNode* head) {
    if(head==NULL||head->next==NULL)
        return true;

    // Get mid point of LL
    ListNode* slow=head;
    ListNode* fast=head;
    while(fast->next!=NULL&&fast->next->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }

    // Reverse 2nd half - slow pointer
    slow->next=reverseList(slow->next);
    slow=slow->next;

    // Check if 1st half == 2nd half
    while(slow!=NULL)
    {   if(head->val!=slow->val)
            return false;
        head=head->next;
        slow=slow->next;
    }
    return true;
}

ListNode* reverseList(ListNode* head) {
    ListNode* pre=NULL;
    ListNode* next=NULL;
    while(head!=NULL){
        next=head->next;
        head->next=pre;
        pre=head;
        head=next;
    }
    return pre;
}