class Solution(object):
    def is_valid(self, i, j):
        return i>=0 and i<self.rows and j>=0 and j<self.cols

    def get_neighbours(self, i ,j):
        return [(i+1,j), (i-1,j), (i,j+1), (i,j-1)]

    def dfs(self,i,j):
        if self.cache[i][j] > 0:
            return self.cache[i][j]
        self.cache[i][j] += 1
        neighbours = self.get_neighbours(i,j)
        res = self.cache[i][j]
        for (n_i,n_j) in neighbours:
            if self.is_valid(n_i,n_j) and self.matrix[n_i][n_j]>self.matrix[i][j]:
                res = max(res, self.cache[i][j]+self.dfs(n_i,n_j))
        self.cache[i][j]=res
        self.max_len = max(self.max_len, self.cache[i][j])
        return self.cache[i][j]

    def longestIncreasingPath(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: int
        """
        if not matrix: return 0
        self.rows = len(matrix)
        self.cols = len(matrix[0])
        self.cache= [[0]*self.cols for _ in range(self.rows)]
        self.max_len=0
        self.matrix = matrix
        for i in range(self.rows):
            for j in range(self.cols):
                self.dfs(i,j)
        # print(self.cache)
        return self.max_len
