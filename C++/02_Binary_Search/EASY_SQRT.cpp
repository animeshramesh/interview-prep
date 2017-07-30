
// Important case to consider is that you need to return 2 when input is 6. So its not exact sqrt()
// You would need to store the ans as ans = mid.
int mySqrt(int x) 
{   if (x == 0 || x == 1) return x;
    int l = 1, r = x, ans;
    while (l <= r) 
    {   int mid = (l+r)/2;

        // mid*mid will go above INT_MAX in some cases.
        // So you need to use mid <= x/mid

        // Go right
        if (mid <= x/mid) 
        {   l = mid + 1;
            ans = mid;
        } 
        
        // Go left
        else 
            r = mid - 1;
    }
    return ans;  
}