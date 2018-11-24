"""
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Solution:
- It's a typical binary search with a slight variation
- Ensure that all the indices are right.
"""

class Solution(object):

    def find_first_occurence(self, nums, target, left, right):
        if left > right: return -1
        mid = (left+right)//2
        if mid == 0 and nums[mid]==target: return 0
        if nums[mid]==target and nums[mid-1]<target: return mid
        if target > nums[mid]:
            return self.find_first_occurence(nums, target, mid+1, right)
        else:
            return self.find_first_occurence(nums, target, left, mid-1)

    def find_last_occurence(self, nums, target, left, right):
        if left > right: return -1
        mid = (left+right)//2
        if mid == len(nums)-1 and nums[mid]==target:
            return len(nums)-1
        if nums[mid]==target and nums[mid+1]>target:
            return mid
        if target >= nums[mid]:
            return self.find_last_occurence(nums, target, mid+1, right)
        else:
            return self.find_last_occurence(nums, target, left, mid-1)


    def searchRange(self, nums, target):
        if not nums: return [-1, -1]
        first = self.find_first_occurence(nums, target, 0, len(nums)-1)
        if first == -1: return [-1, -1]
        last = self.find_last_occurence(nums, target, first, len(nums)-1)
        return [first, last]
