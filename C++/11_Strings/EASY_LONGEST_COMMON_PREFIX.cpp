// Write a function to find the longest common prefix string amongst an array of strings.

// https://leetcode.com/problems/longest-common-prefix/#/solution

// My solution
string longestCommonPrefix(vector<string>& strs) {
    string prefix = "";
    if (strs.size() == 0) return prefix;
    
    // Get smallest length
    int l = INT_MAX;
    for (auto str:strs)
        l = min(l, int(str.size()));
    
    for (int i = 0; i< l; i++)
    {   bool isPrefix = true;
        for (int j = 0; j<strs.size(); j++)
            if (strs[0][i] != strs[j][i])
                isPrefix = false;
        if(isPrefix)
            prefix += char(strs[0][i]);
        else return prefix;
    }
    return prefix;
}