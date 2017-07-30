/*

Given a non-empty string check if it can be constructed by taking a substring of it and appending multiple copies of the substring together. You may assume the given string consists of lowercase English letters only and its length will not exceed 10000.

Example 1:
Input: "abab"

Output: True

Explanation: It's the substring "ab" twice.
Example 2:
Input: "aba"

Output: False
Example 3:
Input: "abcabcabcabc"

Output: True

Explanation: It's the substring "abc" four times. (And the substring "abcabc" twice.)*/

bool repeatedSubstringPattern(string str) {
    int n = str.size();
    
    for (int i = 1; i<=n/2;i++)
    {   string str1 = str.substr(0,i);
        string str2 = str.substr(i,n-i);
        if (str2+str1==str) return true;
    }
    return false;
}