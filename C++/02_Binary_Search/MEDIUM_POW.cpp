// Implement pow(x, n)

// My solution - O(n) time complexity
double myPow(double x, int n) {
    double res = 1;
    if (n<0)
        for(int i = n; i<0; i++)  res/=double(x);
    else
        for (int i = 1; i<=n; i++) res*=x;
    return res;
}

// Optimal solution - Recursive O(logn) solution - Divide and conquer
double myPow(double x, int n) {
    if (n==0) return 1;
    if (n==1) return x;
    if (n==-1) return 1/x;
    double temp = myPow(x, n/2);
    if (n%2==0)
        return temp*temp;
    if (n<0) x = 1/x;
    return x*temp*temp;
}