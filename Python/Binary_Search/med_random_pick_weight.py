"""
Given an array w of positive integers, where w[i] describes the weight of index i,
write a function pickIndex which randomly picks an index in proportion to its weight.


Solution:
- The naive way is to create a new list where each item's frequency is directly proportional to
it's weight. You now just randomly pick an item from this list.
- The smarter way is to use binary search on a cumulative_sum array. You know that the list is sorted
- O(n) time to init and O(logn) time to find index. O(n) space
"""


class Solution:

    def __init__(self, w):
        self.csum = w
        self.n = len(w)
        for i in range(1, self.n):
            self.csum[i] += w[i-1]

    def pickIndex(self):
        seed = random.randint(1,self.csum[-1])
        l,r = 0, self.n-1
        while l<r:
            mid = (l+r)//2
            if seed <= self.csum[mid]:
                r = mid
            else:
                l = mid+1
        return l
