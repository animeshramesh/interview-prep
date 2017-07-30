/* You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, 
the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and 
it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money 
you can rob tonight without alerting the police.
*/

/* This is a dynamic programming question.  At first glance, it appears that the robber could just rob every other house - 
in which case, we ask whether he should start with the first house or the second house; this could maximize the number of houses he robs.  
However, it is possible that neither of these possibilities maximize the amount of money he'd steal (e.g. house 1 and 4 have a million dollars each, and the rest have no money).

Algorithm idea: if there were only k houses, how much money could the robber make?  Calculate this for k=1,2,3,...n (in that order) -
 this calculation will be fast, since each step only requires a small amount of work.

Let M(k) be the amount of money at the kth house, and P(k) be the maximum amount of money he can make if we consider only the first k houses.  Then we have:

P(0)=0
P(1)=M(1)
P(k)=max(P(k−2)+M(k),P(k−1)) (first case=rob the kth house, and some combination of the first k−2, second case=don't rob kth house, and rob some combination of the first k−1).  Keep track of these decisions.

Once you've computed P(n)P(n), you've found the maximum amount of money you can rob, and if you tracked the decisions that led you there (which of the M(k) were added in), you know which houses to rob.
*/

int rob(vector<int> &num) {
    int n = num.size();
    if (n==0) return 0;
    vector<int> result(n+1,0);
    result[1] = num[0];
    for (int i=2;i<=n;i++){
        result[i] = max(result[i-1],result[i-2]+num[i-1]);
    }
    return result[n];
    
    
}

