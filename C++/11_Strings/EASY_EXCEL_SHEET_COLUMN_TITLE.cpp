/* Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 

This problem is not difficult but needs more attention on the format.
General cases are straightforward:
27 -> AA                 27/26 = 1,  27%26 = 1,     1->A, 1->A   thus AA
3  ->  C                    3/26 = 0,    3%26 = C        0->   , 3->C   thus C
53 -> BA                 53/26 = 2,   53%26 = 1      2->B, 1->A   thus BA

Some special cases we need to handle:
26 -> Z                    26/26 = 0,  26%26 = 0
52 -> AZ                 26/26 = 2,   26%26 = 0
*/

// I was trying to think of something too complex. 
// Here is a simple solution I found.
string convertToTitle(int n) 
{
    string res = "";
    while (n>0)
    {
        if (n%26==0)
        {
            res = 'Z' + res;
            n = n/26 -1;
        }
        else
        {
            res = char(n%26 -1 + 'A') + res;
            n = n/26;
        }
    }
    return res;
}