"""
In a string composed of 'L', 'R', and 'X' characters, like "RXXLRXRXL", a move consists of either replacing one occurrence of "XL" with "LX",
or replacing one occurrence of "RX" with "XR".
Given the starting string start and the ending string end, return True if and only if there exists a sequence of moves to transform one string to the other.

Solution:
- The trick is understand that 'L' can move only left and 'R' can move only right.
- You can probably solve this using BFS, but that would use a ton of space.
- O(n) time and O(1) space
- 6 cases below
"""

from collections import Counter
class Solution(object):
    def canTransform(self, start, end):

        # Case 1: When lengths are unequal
        if Counter(start) != Counter(end): return False
        p1, p2, n = 0, 0, len(start)

        while (p1 < n and p2 < n):

            # Get the first occurence of non-X character
            while p1 < n and start[p1] == 'X':
                p1 += 1

            while p2 < n and end[p2] == 'X':
                p2 += 1

            # Case 2. If both are done, return true
            if (p1 == n) and (p2 == n): return True

            # Case 3. Where only one search is done
            if (p1 == n) or (p2 == n): return False

            # Case 4. Both characters must be either 'L' or 'R'
            if start[p1] != end[p2]: return False

            # Case 5. 'L' can only move left
            if start[p1] == 'L' and p2 > p1: return False

            # Case 6. 'R' can only move right
            if start[p1] == 'R' and p1 > p2: return False

            p1+=1
            p2+=1

        return True
