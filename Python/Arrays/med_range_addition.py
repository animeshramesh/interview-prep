"""


Assume you have an array of length n initialized with all 0's and are given k update operations.

Each operation is represented as a triplet: [startIndex, endIndex, inc]
which increments each element of subarray A[startIndex ... endIndex] (startIndex and endIndex inclusive) with inc.


Solution:
- In the naive approach, you increment all elements. That's O(n*k)
- But you dont need to modify all values. You increment only the starting index and decrement the index just after the range
- Finally you just need to do a cumulative_sum. This aproach is O(n+k)
"""


class Solution(object):
    def getModifiedArray(self, length, updates):
        """
        :type length: int
        :type updates: List[List[int]]
        :rtype: List[int]
        """
        res = [0] * length
        for update in updates:
            start, end, inc = update
            res[start] += inc

            if end + 1 <= length - 1:
                res[end+1] -= inc

        sum = 0
        for i in range(length):
            sum += res[i]
            res[i] = sum
        return res
