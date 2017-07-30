/* Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.
*/

// My solution - Copied the base code from REMOVE_DUPLICATES_SORTED_1
int removeDuplicates(vector<int>& nums) {
    if(nums.size() <=1) return nums.size();
    int i = 0, j = 1;
    map<int, int> counts;
    counts[nums[0]]=1;
    
    while(j < nums.size())
    {   if (nums[j]!=nums[j-1])
        {   nums[++i]=nums[j];
            counts[nums[i]]=1;                    
        }
        else
        {
            if (counts[nums[i]]<2)
            {
                nums[++i]=nums[j];
                counts[nums[i]]++;
            }
        }
        j++;
    }
    return i+1;
}

// Optimal solution
int removeDuplicates(vector<int>& nums) {
    int i = 0;
    for (int n : nums)
        if (i < 2 || n > nums[i-2])
            nums[i++] = n;
    return i;
}