/* A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.
*/

// https://stackoverflow.com/questions/20342462/review-an-answer-decode-ways
// https://www.youtube.com/watch?v=aCKyFYF9_Bg
// Solution from http://bangbingsyb.blogspot.com/2014/11/leetcode-decode-ways.html
int numDecodings(string s) {
    if(s.empty() || s[0]<'1' || s[0]>'9') return 0;
    vector<int> dp(s.size()+1,0);
    dp[0] = dp[1] = 1;  // dp[i] is the number of ways to decode str[0:i]
    
    for(int i=1; i<s.size(); i++) 
    {
        if(!isdigit(s[i])) return 0;
        int v = (s[i-1]-'0')*10 + (s[i]-'0');
        if(v<=26 && v>9) dp[i+1] += dp[i-1];
        if(s[i]!='0') dp[i+1] += dp[i];
        if(dp[i+1]==0) return 0;
    }
    return dp[s.size()];
}