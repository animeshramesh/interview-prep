/* 
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, 
determine if s can be segmented into a space-separated sequence of one or more dictionary words. 
You may assume the dictionary does not contain duplicate words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".
*/

// Time complexity - O(n^2)
// Space complexity - O(n)
bool wordBreak(string s, vector<string>& wordList) 
{
    if (wordList.size() == 0)
        return 0;

    // Make a set for easy searching
    unordered_set<string> wordDict;
    for (string word:wordList)
        wordDict.insert(word);
    
    int n = s.size();
    // dp[i] is set to true if a valid word ends there.
    vector<bool> dp(n+1, false);
    dp[0] = true;
    
    //Be very careful of the indices - i and j
    // Convention for s and dp is different
    for (int i = 0; i<n; i++)
    {   for (int j = 0; j<=i; j++)
        {   string word = s.substr(j, i-j+1);
            if (dp[j] && wordDict.find(word) != wordDict.end())
            {
                dp[i+1] = true;
                break;
            }
        }
    }
    return dp[n];
}