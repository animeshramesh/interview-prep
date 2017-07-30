/* Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.
*/

// My solution. Its a bit lengthy and dirty
bool isPalindrome(string s) {
    for (int i = 0; i<s.size(); i++) s[i] = tolower(s[i]);
    int left = 0, right = s.size()-1;
    
    // Start with alphanumeric char
    while (true)
    {   if (!isalnum(s[left]))
            left++;
        else
            break;
    }  
    
    // End with alphanumeric char
    while (true)
    {   if (!isalnum(s[right]))
            right--;
        else
            break;
    } 
    
    while (left<=right)
    {   
        if (s[left] != s[right]) return false;
        left++;
        right--;
        
        if (left>right)
            break;
        
        while(!isalnum(s[left])) left++;
        while(!isalnum(s[right])) right--;
    }
    
    return true;
    
}

// My second solution. Missed the left < right condition. 
bool isPalindrome(string s) {
    for (int i = 0; i<s.size(); i++) s[i] = tolower(s[i]);
    int left = 0, right = s.size()-1;
    while (left<=right)
    {   while(!isalnum(s[left]) && left < right) left++;
        while(!isalnum(s[right]) && left < right) right--;
        if (s[left] != s[right]) return false;
        left++;
        right--;
    }
    return true;
}

// Optimal solution
bool isPalindrome(string s) {
    for (int i = 0, j = s.size() - 1; i < j; i++, j--) { // Move 2 pointers from each end until they collide
        while (isalnum(s[i]) == false && i < j) i++; // Increment left pointer if not alphanumeric
        while (isalnum(s[j]) == false && i < j) j--; // Decrement right pointer if no alphanumeric
        if (tolower(s[i]) != tolower(s[j])) return false; // Exit and return error if not match
    }
    
    return true;
}