"""
[-2,1,-3,4,-1,2,1,-5,4] -> 6

Kadane's Algorithm
O(n) time and O(1) space
"""

class Solution(object):
    def maxSubArray(self, nums):
        if not nums: return 0
        max_sum, cur_sum = nums[0], nums[0]

        for num in nums[1:]:
            cur_sum = max(num, cur_sum + num)
            max_sum = max(max_sum, cur_sum)

        return max_sum
