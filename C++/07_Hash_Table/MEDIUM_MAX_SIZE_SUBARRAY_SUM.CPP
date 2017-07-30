/* 
Given an array nums and a target value k, find the maximum length of a subarray that sums to k. 
If there isn't one, return 0 instead.
Example 1:
Given nums = [1, -1, 5, -2, 3], k = 3,
return 4. (because the subarray [1, -1, 5, -2] sums to 3 and is the longest)
Example 2:
Given nums = [-2, -1, 2, 1], k = 1,
return 2. (because the subarray [-1, 2] sums to 1 and is the longest)

Follow Up:
Can you do it in O(n) time?
Understand the problem:

The problem is equal to: find out a range from i to j, in which the sum (nums[i], ..., nums[j]) = k. 
What is the maximal range? 

So we can first calculate the prefix sum of each number, so sum(i, j) = sum(j) - sum(i - 1) = k. 
Therefore, for each sum(j), we only need to check if there was a sum(i - 1) which equals to sum(j) - k. 
We can use a hash map to store the previous calculated sum. 

*/

// Cumulative sum trick
int maxSubArrayLen(vector<int>& nums, int k) {
    int res = 0;
    unordered_map<int, int> sum2idx; 
    sum2idx[0] = -1;	// IMPORTANT STEP. WHY?
    for (int i = 0, sum = 0; i < nums.size(); ++i) {
        sum += nums[i];
        if (sum2idx.find(sum) == sum2idx.end()) sum2idx[sum] = i;
        if (sum2idx.find(sum-k) != sum2idx.end()) res = max(res, i-sum2idx[sum-k]);	// Find out if the difference exists             
    }
    return res;
}