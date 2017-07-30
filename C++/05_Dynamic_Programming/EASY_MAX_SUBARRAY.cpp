int maxSubArray(vector<int>& nums) {
        
    int gSum = nums[0], cSum = nums[0];
    
    for (int i = 1; i<nums.size(); i++)
    {
        cSum += nums[i];
        cSum = max(nums[i], cSum);
        gSum = max(gSum, cSum);
        
    }
    return gSum;
}

int maxSubArraySum(int a[], int size)
{
   int max_so_far = a[0];
   int curr_max = a[0];
 
   for (int i = 1; i < size; i++)
   {
        curr_max = max(a[i], curr_max+a[i]);
        max_so_far = max(max_so_far, curr_max);
   }
   return max_so_far;
}
