/* Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
Example:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2. */

// My solution
// Idea is that each item in the stack will have two values - val, currentMin
class MinStack {
public:

    stack<pair<int, int>> st;    
    void push(int x) {
        if (st.size() == 0)
            st.push(make_pair(x,x));
        
        else
        {   int currentMin = st.top().second;
            st.push(make_pair(x, min(currentMin, x)));
        }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};