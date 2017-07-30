/* 

Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.


*/

int lengthOfLongestSubstring(string s) {
    int i=0, j=0, n=s.size(), ans=0;
    
    set<char> ref;
    
    while(i<n&&j<n)
    {   if (ref.find(s[j]) == ref.end())
        {
            ref.insert(s[j]);
            ans = max(ans, j-i+1);
            j++;
        }
        else
        {   ref.erase(ref.find(s[i]));
            i++;    
        }
        
    }
    return ans;
}