/* Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.

This is case sensitive, for example "Aa" is not considered a palindrome here.

Note:
Assume the length of given string will not exceed 1,010. */

// My solution
int longestPalindrome(string s) {
    map<char, int> counts;
    for (char c:s)
    {   if (counts.find(c) == counts.end())
            counts[c]=1;
        else counts[c]++;
    }
    
    int l = 0;
    for (auto it:counts)
    {   if (it.second % 2 == 0)
            l+=it.second;
        else l += it.second-1;
    }    
    
    if (l < s.size()) l++;
    return l;
}

