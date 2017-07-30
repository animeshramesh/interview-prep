/* Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
Return 4.
*/

// https://www.youtube.com/watch?v=_Lf1looyJMU
// Time complexity : O(mn) Single pass.
// Space complexity : O(mn). Another matrix of same size is used for dp.
int maximalSquare(vector<vector<char>>& matrix) {
    if (matrix.size() == 0) return 0;
    int m = matrix.size(), n = matrix[0].size();
    
    // dp(i,j) represents the side length of the maximum square whose bottom right corner 
    // is the cell with index (i,j) in the original matrix.
    int dp[m+1][n+1];

    memset(dp, 0, sizeof(dp));
    int ans = 0;
    for (int i = 0; i<m; i++)
    {
        for (int j = 0; j<n; j++)
        {
            if (matrix[i][j]=='1')
            {
                dp[i+1][j+1] = min(dp[i][j], min(dp[i][j+1], dp[i+1][j]))+1;
            }
            ans = max(ans, dp[i+1][j+1]);
        }
    }
    return ans*ans;
}

// There's another solution
// Time complexity : O(mn) Single pass.
// Space complexity : O(n). 