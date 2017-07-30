/* 
There are a row of n houses, each house can be painted with one of the k colors.
 The cost of painting each house with a certain color is different. 
 You have to paint all the houses such that no two adjacent houses have the same color.
The cost of painting each house with a certain color is represented by a n x k cost matrix. 
For example, costs[0][0] is the cost of painting house 0 with color 0; costs[1][2] is the cost of painting house 1 with color 2,
 and so on... Find the minimum cost to paint all houses.

Note:
All costs are positive integers.
Follow up:
Could you solve it in O(nk) runtime? */


/*
Understand the problem:
This is a classic knapsack problem. 
 -- Define dp[n][k], where dp[i][j] means for house i with color j the minimum cost. 
 -- Initial value: dp[0][j] = costs[0][j]. For others, dp[i][j] = Integer.MAX_VALUE;, i >= 1
 -- Transit function: dp[i][j] = Math.min(dp[i][j], dp[i - 1][k] + cost[i][j]), where k != j.
 -- Final state: Min(dp[n - 1][k]).

*/

// Time complexity - O(n*k*k).
// Space complexity - O(n*k).

int minCostII(vector<vector<int>> costs) 
{
    if (costs.size() == 0) return 0;
     
    int n = costs.size();
    int k = costs[0].size();
     
    // dp[i][j] means the min cost painting for house i, with color j
    int dp[n][k];
    memset(dp, INT_MAX, sizeof(dp));
     
    // Initialization - first row
    for (int i = 0; i < k; i++) 
        dp[0][i] = costs[0][i];
    
     
    for (int i = 1; i < n; i++) 
    {
        for (int j = 0; j < k; j++) 
        {
            for (int m = 0; m < k; m++) 
            {   // All columns which don't belong to this color
                if (m != j) 
                {
                    dp[i][j] = min(dp[i][j], dp[i - 1][m] + costs[i][j]);
                }
            }
        }
    }
     
    // Minimum cost is the min value in the last row
    int minCost = INT_MAX;
    for (int i = 0; i < k; i++) 
        minCost = min(minCost, dp[n - 1][i]);
    
     
    return minCost;
}


// Another optimization is that since you only need the previous row, 
// you can work with only 1D array


// Solution 2
// Time complexity - O(nk)
// Space complexity - O(1)
// I didn't understand this solution
public int minCostII(vector<vector<int>> costs) {
    if (costs.size() == 0) return 0;
     
    int n = costs.size();
    int k = costs[0].size();
     
    // dp[j] means the min cost for color j
    int dp[k];
    memset(dp, INT_MAX, sizeof(dp));
    int min1 = 0;
    int min2 = 0;

    for (int i = 0; i < n; i++) 
    {
        int oldMin1 = min1;
        int oldMin2 = min2;
         
        min1 = INT_MAX;
        min2 = INT_MAX;
         
        for (int j = 0; j < k; j++) 
        {
            if (dp[j] != oldMin1 || oldMin1 == oldMin2) 
                dp[j] = oldMin1 + costs[i][j];
            else 
                dp[j] = oldMin2 + costs[i][j];
            
             
            if (min1 <= dp[j]) 
                min2 = min(min2, dp[j]);
            else 
            {
                min2 = min1;
                min1 = dp[j];
            }
        }
         
    }
     
    return min1;
}