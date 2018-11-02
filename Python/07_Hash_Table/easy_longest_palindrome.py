'''
Given a string which consists of lowercase or uppercase letters,
find the length of the longest palindromes that can be built with those letters.

This is case sensitive, for example "Aa" is not considered a palindrome here.
'''

'''
Time -> O(n)
Space -> O(n) [in dict]
'''
class Solution:
    def longestPalindrome(self, strng):

        # Create a frequency dictionary
        ref = {}
        for s in strng:
            if s in ref:
                ref[s] += 1
            else:
                ref[s] = 1

        ans = 0
        extra_char = False
        for k, v in ref.iteritems():
            # Use all characters if it's even
            if v % 2 == 0:
                ans += v
            else:
                ans += v-1
                extra_char = True

        # Instead of the following condition you can also say
        # if ans < len(strng)
        if extra_char:
            return ans + 1
        return ans
