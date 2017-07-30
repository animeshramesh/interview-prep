// Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// My solution - I miss st.empty condition in the loop!
bool isValid(string s) {
    stack<char> st;
    
    for (int i = 0; i<s.size(); i++)
    {
        // Starting braces
        if (s[i] == '{' || s[i] =='(' || s[i]=='[')
            st.push(s[i]);
        else if (s[i]=='}' && !st.empty() && st.top() == '{') st.pop();
        else if (s[i]==']' && !st.empty() && st.top() == '[') st.pop();
        else if (s[i]==')' && !st.empty() && st.top() == '(') st.pop();
        else return false;
    }
        
    return st.empty();
}