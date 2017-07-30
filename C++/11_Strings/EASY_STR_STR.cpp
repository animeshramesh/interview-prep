/* Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

*/

//My solution
int strStr(string haystack, string needle) {
    int i = 0, m = haystack.size(), n = needle.size();
    // Ask what if m==0 or n==0?
    if (n == 0) return 0;
    if (m == 0) return -1;
    
    while (i<=m-n)
    {	if(haystack[i] == needle[0])
        {   int ind = i;
            for (int j=0; j<n; j++, i++)
            {
                if (haystack[i]!=needle[j])
                {
                    i = ind+1;
                    break;
                };
            }
            if (i == ind+n)
                return ind;
        }
        else i++;
    }
    return -1;
}

// Another elegant solution
// O(mn)
int strStr(string haystack, string needle) {
    int m = haystack.length(), n = needle.length();
    if (!n) return 0;
    for (int i = 0; i < m - n + 1; i++) 
    {
        int j = 0;
        for (; j < n; j++)
            if (haystack[i + j] != needle[j])
                break;
        if (j == n) return i;
    }
    return -1;
}