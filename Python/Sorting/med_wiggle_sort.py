"""
nums[0] <= nums[1] >= nums[2] <= nums[3]...

- Approach 1: O(nlogn)
    Sort and swap adjacent elements

- Approach 2: O(n)
    Iterate and check if adjacent elements fail condition, if yes, swap
    Cleaner - Note that condition is based on odd/even index
"""
