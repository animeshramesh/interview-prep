/* Given an array of n positive integers and a positive integer s, find the minimal length of a 
contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.

For example, given the array [2,3,1,2,4,3] and s = 7,
the subarray [4,3] has the minimal length under the problem constraint. */

// O(n) two-pointer solution
// https://leetcode.com/problems/minimum-size-subarray-sum/#/solution
int minSubArrayLen(int s, vector<int>& nums)
{
    int n = nums.size();
    int count = INT_MAX;
    int left = 0;
    int sum = 0;
    for (int i = 0; i < n; i++) 
    {
        sum += nums[i];
        while (sum >= s) 
        {
            count = min(count, i - left + 1);
            sum -= nums[left];
            left++;
        }
    }
    return (count != INT_MAX) ? count : 0;
}
    
// Bruteforce - O(n^3)
int minSubArrayLen(int s, vector<int>& nums)
{
    int n = nums.size();
    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int sum = 0;
            for (int k = i; k <= j; k++) {
                sum += nums[k];
            }
            if (sum >= s) {
                ans = min(ans, (j - i + 1));
                break; //Found the smallest subarray with sum>=s starting with index i, hence move to next index
            }
        }
    }
    return (ans != INT_MAX) ? ans : 0;
}
