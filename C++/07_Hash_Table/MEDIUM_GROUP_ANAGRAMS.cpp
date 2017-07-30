/* Given an array of strings, group anagrams together.

For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
Return:

[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note: All inputs will be in lower-case. */

// My solution - Ran into some pointer errors. Probably while using auto.
vector<int> getCounts(string s)
{
    vector<int> ref(26,0);
    for (auto c:s) ref[c-48]++;
    return ref;
}

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    map<vector<int>, vector<string>> ref;
    for (auto str:strs)
    {
        vector<int> counts = getCounts(str);
        if (ref.find(counts)==ref.end())
        {
            vector<string> t;
            t.push_back(str);
            ref[counts]=t;
        }
            
        else ref[counts].push_back(str);
    }
    vector<vector<string>> result;
    for (auto it :ref)
    {
        result.push_back(it.second);
    }
    return result;
}

// Clean code
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    map<string, vector<string>> count;
    int i = 0;
    for (auto s : strs)     // s is a copy of strs[i]
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