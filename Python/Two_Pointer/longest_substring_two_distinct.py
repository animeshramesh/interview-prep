"""
Given a string s , find the length of the longest substring t  that contains at most 2 distinct characters.


Solution:
I used a hash to store a mapping of the character to its latest position within the string.
When the hash has K+1 different characters, the key is here to find the character with the smallest
(left-most) position and eliminate it from the hash.

The left pointer then starts from the next character after the eliminated character.
"""

class Solution(object):
    def lengthOfLongestSubstringTwoDistinct(self, s):
        """
        :type s: str
        :rtype: int
        """
        left, longest, d = 0, 0, {}
        maximum_distinct = 2
        for index, char in list(enumerate(s)):
            d[char] = index
            if len(d.keys()) == maximum_distinct + 1:
                index_to_remove = min(d.values())
                d.pop(s[index_to_remove], None)
                left = index_to_remove + 1
            longest = max(longest, index - left + 1)
        return longest
