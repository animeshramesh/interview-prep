"""
"babad" -> "bab"
"cbbd" -> "bb"

Solution:
- Naive approach is to evaluate all substrings -> n^2 x n comparisons = O(n^3)
- Following approach is to expand on centre -> O(n^2) time and O(1) space
- There's also a DP approach, but I am skipping it for now
- There's also Manacher's algorithm which uses only O(n) time
"""

class Solution(object):

    def expand(self, s, start, end):
        while (start >= 0 and end < len(s) and s[start]==s[end]):
            start -= 1
            end += 1
        start += 1
        end -= 1
        return s[start:end+1]

    def longestPalindrome(self, s):

        res = ""
        for i in range(len(s)):

            # Case for palindrome with odd length
            res1 = self.expand(s, i, i)

            # Case for palindrome with even length - two centres
            res2 = self.expand(s, i, i+1)

            max_res = res1 if len(res1) > len(res2) else res2
            res = max_res if len(max_res) > len(res) else res
        return res
