class Solution:

    """
    Start from O(m-1, n-1). Bottom most row and right mist column are all 1s
    Now use DP to determine the function
    """
    # @return an integer
    def uniquePaths(self, m, n):
        aux = [[1 for x in range(n)] for x in range(m)]
        for i in range(1, m):
            for j in range(1, n):
                aux[i][j] = aux[i][j-1]+aux[i-1][j]
        return aux[-1][-1]
