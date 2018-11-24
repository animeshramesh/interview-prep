## Recursive - O(2^n)
def num_decodings(i, s):
    n = len(s)
    if i == n: return 1
    if s[i] == '0': return 0
    res = num_decodings(i+1, s)
    if i < n-1 and (s[i]=='1'or (s[p]=='2' and s[p+1]<'7')):
        res += numDecodings(p+2,s);
    return res

# DP - O(N) time and O(n) space
# dp[i] = the way to decode a string of size i
def num_decodings(s):
    n = len(s)
    if s == "": return 0
    dp = [0]*(n+1)
    dp[0] = 1
    for i in range(1, len(s)+1):
        if s[i-1] != "0":
            dp[i] += dp[i-1]
        if i > 1 and s[i-2:i] < "27" and s[i-2:i] > "09":  #"01"ways = 0
            dp[i] += dp[i-2]
    return dp[len(s)]
