/* 
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/

// Time Complexity - O(n^k)
// Space Complexity - O(n^k)
void buildCombinations(int begin, int n, int k, vector<int>& intermediate, vector<vector<int>>& result)
{   if(intermediate.size() == k)
    {
        result.push_back(intermediate);
        return;
    }
    
    for(int i = begin; i<=n; i++)
    {   intermediate.push_back(i);
        buildCombinations(i+1, n, k, intermediate, result);
        intermediate.pop_back();
    }
    
}
vector<vector<int>> combine(int n, int k) 
{   vector<vector<int>> result;
    vector<int> intermediate;
    
    buildCombinations(1, n, k, intermediate, result);
    
    return result;
}