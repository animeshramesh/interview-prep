/* 
Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") ? false
isMatch("aa","aa") ? true
isMatch("aaa","aa") ? false
isMatch("aa", "*") ? true
isMatch("aa", "a*") ? true
isMatch("ab", "?*") ? true
isMatch("aab", "c*a*b") ? false
*/


// https://www.youtube.com/watch?v=3ZDZ-N0EPV0
// Time complexity - O(mn)
// Space complexity - O(mn)
// There are other solutions which have O(1) space complexity. I didn't undertstand those.
bool isMatch(string s, string p) 
{
    int m = s.size(); 
    int n = p.size();
    bool res[m+1][n+1];
    memset(res, false, sizeof(res));
    res[0][0] = true;
    
    // If '*' is the first char in the pattern, make it true
    for (int i = 1; i <= n; ++i) 
    {
        if(p[i - 1] == '*') res[0][i] = true;
        else break;
    }

    // Build the DP solution
    for (int i = 1 ; i <= m; ++i) 
    {
        for (int j = 1; j <= n; ++j) 
        {   
            // Case 1 : 
            // both characters are same
            // or pattern[i-1] = '?'
            // consider the top-left cell
            if (s[i - 1] == p[j - 1] || p[j - 1] =='?') res[i][j] = res[i - 1][j - 1];
            
            // If it's a '*'
            // Consider the left and top cells.
            // Left cell means -> Is the pattern same if you remove the '*'? - * counts 
            // Top cell means -> ???
            // If either of them is true, then make it true
            if (p[j - 1] == '*') 
                res[i][j] = res[i - 1][j] || res[i][j - 1];
            
        }
    }
    
    return res[m][n];
}