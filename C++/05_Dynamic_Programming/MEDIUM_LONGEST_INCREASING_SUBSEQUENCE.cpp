/* Given an unsorted array of integers, find the length of longest increasing subsequence.

For example,
Given [10, 9, 2, 5, 3, 7, 101, 18],
The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that there may be more than one LIS combination, it is only necessary for you to return the length.

Your algorithm should run in O(n2) complexity.

Follow up: Could you improve it to O(n log n) time complexity?
*/

// Time complexity - O(n^2)
// Space complexity - O(n)
// Brute force is 2^n (time) and O(n^2) space
int lengthOfLIS(vector<int>& nums) 
{
    // dp - to store the max length of increasing subsequence formed by including the currently encountered element.
    vector<int> dp(nums.size(), 1);
    if (nums.empty()) return 0;
    int ans = 1;

    for (int i = 1; i<nums.size(); i++)
    {   for (int j = 0; j<i; j++)
            if (nums[j]<nums[i])
                dp[i]=max(dp[i], dp[j]+1);
        ans = max(ans, dp[i]);
    }
    return ans;
}


// There's also a binary search + DP solution nlogn
// https://leetcode.com/problems/longest-increasing-subsequence/#/solution