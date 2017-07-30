/* Given a non-empty array of integers, return the k most frequent elements.

For example,
Given [1,1,1,2,2,3] and k = 2, return [1,2].

Note: 
You may assume k is always valid, 1 ? k ? number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
*/

// Time:  O(n) ~ O(n^2), O(n) on average.
// Space: O(n)

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map<int, int> counts;
        for (const auto& i : nums) 
            ++counts[i];
        

        vector<pair<int, int>> p;
        for (auto it = counts.begin(); it != counts.end(); ++it) 
            p.push_back(-(it->second), it->first);
        
        sort(p.begin(), p.end());
        //nth_element(p.begin(), p.begin() + k - 1, p.end()); // more efficient than whole sorting

        vector<int> result;
        for (int i = 0; i < k; ++i) 
            result.push_back(p[i].second);
        
        return result;
    }
};

// Time:  O(nlogk)
// Space: O(n)
// Heap solution.
class Solution2 {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map<int, int> counts;
        for (int i = 0; i < nums.size(); ++i) 
            ++counts[nums[i]];
        
        priority_queue<pair<int, int>> heap;
        for (auto it = counts.begin(); it != counts.end(); ++it) 
        {
            heap.push(make_pair(-(it->second), it->first));
            if (heap.size() == k + 1) 
            {
                heap.pop();
                break;
            }    
            
        }

        vector<int> result;
        while (!heap.empty()) 
        {   result.push_back(heap.top().second);
            heap.pop();
        }

        reverse(result.begin(), result.end());
        return result;
    }
};