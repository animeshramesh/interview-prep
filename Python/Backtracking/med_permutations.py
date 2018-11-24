def permute(self, nums):

    result = []
    def permute_helper(i):
        if i == len(nums):
            result.append(nums.copy())
            return

        for j in range(i, len(nums)):
            nums[i], nums[j] = nums[j], nums[i]
            permute_helper(i + 1)
            nums[i], nums[j] = nums[j], nums[i]

    permute_helper(0)
    return result
