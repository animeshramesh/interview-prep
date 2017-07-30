/* 
Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") ? false
isMatch("aa","aa") ? true
isMatch("aaa","aa") ? false
isMatch("aa", "a*") ? true
isMatch("aa", ".*") ? true
isMatch("ab", ".*") ? true
isMatch("aab", "c*a*b") ? true

*/

// https://www.youtube.com/watch?v=l3hda49XcDE&t=736s
bool isMatch(string s, string p) {
    int m = s.size(), n = p.size();
    
    // Initialize dp 2D matrix
    bool dp[m+1][n+1];
    memset(dp, false, sizeof(dp));
    dp[0][0] = true;
    
    for(int i=0; i<=m; i++) 
    {
        for(int j=1; j<=n; j++) 
        {   
            // Case 1: When both characters are matching
            // Remove 1 char each from string and pattern and compare
            // Top-left cell in dp matrix
            if(p[j-1]!='.' && p[j-1]!='*')
            {
                if(i>0 && s[i-1]==p[j-1] && dp[i-1][j-1])
                    dp[i][j] = true;
            }
            
            // Case 2 : In case of a '.', remove 1 char each from string and pattern and compare
            // Top-left cell in dp matrix
            else if(i>0 && p[j-1]=='.' && dp[i-1][j-1]) dp[i][j] = true;
            
            // p[j-1] is a '*' now
            else if(j>1 && p[j-1]=='*') 
            {  //'*' cannot be the 1st element - 1st column cannot be true. Try it out.
                // Left1 || left 2 
                if(dp[i][j-1] || dp[i][j-2])  // match 1 or 0 preceding element
                    dp[i][j] = true;
                
                // if pattern is '.*'
                // or Remove 1 char each from string and pattern and compare
                // top cell
                // IMPORTANT CONDITION
                else if(i>0 && (p[j-2]==s[i-1] || p[j-2]=='.') && dp[i-1][j]) // match multiple preceding elements
                    dp[i][j] = true;
            }
        }
    }
    return dp[m][n];
}