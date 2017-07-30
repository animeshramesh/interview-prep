/* Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
*/

// My solution
string addBinary(string a, string b) {
    // Pad zeros
    int m = a.size();
    int n = b.size();
    if (m<n)
        for (int i = 0; i<n-m; i++) a = "0"+a;
    else
        for (int i = 0; i<m-n; i++) b = "0"+b;
    
    int carry = 0;
    string result = "";
    for (int i = a.size()-1; i>=0; i--)
    {
        int s = carry + (int(a[i])-48) + (int(b[i])-48);   
        cout << s << endl;
        if (s > 1) carry = 1;
        else carry = 0;

        if (s%2==0) 
            result = "0"+result;
        else result="1"+result;
    }
    if (carry == 1)
        result = "1"+result;
    
    return result;
}

// Optimal code
string addBinary(string a, string b)
{
    string res = "";
    
    int c = 0, i = a.size() - 1, j = b.size() - 1;
    while(i >= 0 || j >= 0 || c == 1)
    {   
        if (i>=0)
        {
            c += a[i] - '0';
            i--;
        }    
        if (j>=0)
        {
            c += b[j] - '0';
            j--;
        } 

        // Important trick
        res = char(c % 2 + '0') + res;
        c /= 2;
    }
    
    return res;
}