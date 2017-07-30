/* Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/

// Initially thought of two pass hash table approach. 
// But a single pass is enough as shown below.
// Use unordered_set!!
vector<int> twoSum(vector<int>& nums, int target) {
    map<int, int> ref;
    vector<int> result;
    for (int i = 0; i<nums.size(); i++)
    {   
        int diff = target - nums[i];
        if (ref.find(diff)!= ref.end() && ref[diff]!=i)
        {
            result.push_back(i);
            result.push_back(ref[diff]);
            return result;
        }
        ref[nums[i]]=i;
    }
    return result;
}