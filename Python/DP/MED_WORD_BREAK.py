"""
s = "leetcode", wordDict = ["leet", "code"] -> True
s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"] -> False
s = "applepenapple", wordDict = ["apple", "pen"] -> True


Solution:
- First ask what should empty string return. (It should be True)
- The naive solution is O(2^n) time and O(n) space
- For DP, create a dp list where dp[i] denotes whether s[:i] can be broken into words in word_dict
- DP solution is O(n^2) time and O(n) space
- dp[i] will be true only if dp[j] is True and s[j:i] in dictionary
"""

class Solution(object):
    def wordBreak(self, s, wordDict):
        word_dict = set(wordDict)
        if not word_dict: return False
        dp = [False] * (n+1)
        dp[0] = True
        for i in range(1, n+1):
            for j in range(0, i):
                if dp[j] and s[j:i] in word_dict:
                    dp[i]=True

        return dp[-1]
