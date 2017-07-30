/* 
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Note: Given n will be a positive integer.
*/
int climbStairs(int n) {
    if (n<3) return n;
    int s[n];
    s[0]=1;
    s[1]=1;
    s[2]=2;
    
    for (int i = 3; i<=n; i++)
        s[i]=s[i-1]+s[i-2];
    return s[n];    
    
}