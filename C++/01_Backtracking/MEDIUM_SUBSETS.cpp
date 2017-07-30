/* Given a set of distinct integers, nums, return all possible subsets.

Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/
// O(n * 2^n) time
vector<vector<int>> subsets(vector<int>& nums) 
{
    sort(nums.begin(), nums.end()); // Not needed
    vector<vector<int>> res;
    vector<int> temp;  
    genSubsets(nums, 0, sub, res);
    return res; 
}
void genSubsets(vector<int>& nums, int start, vector<int>& temp, vector<vector<int>>& res) 
{
    res.push_back(temp);
    for (int i = start; i < nums.size(); i++) 
    {
        temp.push_back(nums[i]);
        genSubsets(nums, i + 1, temp, res);
        temp.pop_back();
    }
}