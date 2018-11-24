"""

https://leetcode.com/problems/queue-reconstruction-by-height/discuss/167308/Python-solution

The key to solve this problem is finding the start point of reconstruction.
For this problem, we can start adding the largest element first.
The basic idea is keep adding the largest element each time, until all elements are in place.

O(n^2) time
"""

class Solution(object):
    def reconstructQueue(self, people):
        if not people:
            return []
        n = len(people)
        people_sorted = sorted(people, key = lambda x: (-x[0],x[1]))
        res = [people_sorted[0]]
        for i in range(1,n):
            h, k = people_sorted[i]
            res.insert(k, people_sorted[i])
        return res
