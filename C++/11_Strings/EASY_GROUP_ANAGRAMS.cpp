/* Given an array of strings, group anagrams together.

For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
Return:

[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note: All inputs will be in lower-case.*/

vector<vector<string>> groupAnagrams(vector<string>& strs) {
   map<string, vector<string>> count;
    int i = 0;
    for (auto s : strs)
    {
        sort(s.begin(), s.end());
        count[s].push_back(strs[i++]);
    }
    vector<vector<string>> res;
    for (auto n : count){
        sort(n.second.begin(), n.second.end());
        res.push_back(n.second);
    }
    return res;
}