"""

           []
       /    |    \
    [1]    [2]    [3]
  /   |     |
[1,2] [1,3] [2,3]
 |
 [1,2,3]
"""


def subsets1(self, nums):
    res = []
    self.dfs(sorted(nums), 0, [], res)
    return res

def dfs(self, nums, index, path, res):
    res.append(path)
    for i in xrange(index, len(nums)):
        self.dfs(nums, i+1, path+[nums[i]], res)
