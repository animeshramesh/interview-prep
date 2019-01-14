"""
You have only 0, 1 and 2
Push all 0s to left and 2s to the right
"""
class Solution(object):
    def sortColors(self, A):

        n = len(A)
        l, r = 0, n - 1
        for i in range(r+1):
            while A[i]==2 and i<r:
                A[i], A[r] = A[r], A[i]
                r -= 1
            while A[i]==0 and i>l:
                A[i], A[l] = A[l], A[i]
                l += 1
