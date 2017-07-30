class Solution {
    struct compare {
        bool operator()(const ListNode* l, const ListNode* r) {
            return l->val > r->val;
        }
    };
    
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Note the comparator used here
        // Note the 1st 2 arguments passed to priority queue
        // I think for custom comparator, you would say ListNode *, vector<ListNode*>
        priority_queue<ListNode *, vector<ListNode *>, compare> q;

        // Pushing all the 1st elements of the list
        for (auto l : lists) 
            if (l)     // Push only if it's not null
                q.push(l);
            
        
        
        if (q.empty()) 
            return NULL;
        
        
        // This is a reference to the start of the result
        ListNode* result = q.top();
        q.pop();
        if (result->next) 
            q.push(result->next);
        

        // The tail would be updated in every iteration
        ListNode* tail = result;            
        while (!q.empty()) 
        {
            tail->next = q.top();
            q.pop();
            tail = tail->next;
            if (tail->next) 
                q.push(tail->next);
            
        }
        
        return result;
    }
};