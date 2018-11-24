class Solution(object):
    def nextGreaterElement(self, findNums, nums):
        d = {}
        st = []
        ans = []

        for x in nums:
            while len(st) and st[-1] < x:
                d[st.pop()] = x
            st.append(x)

        for x in findNums:
            ans.append(d.get(x, -1))

        return ans
