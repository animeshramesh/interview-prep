/* 
The count-and-say sequence is the sequence of integers with the first five terms as following:

1.     1
2.     11
3.     21
4.     1211
5.     111221
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth term of the count-and-say sequence.

Note: Each term of the sequence of integers will be represented as a string.

Example 1:

Input: 1
Output: "1"
Example 2:

Input: 4
Output: "1211"

*/

string countAndSay(int n) 
{
    if (n == 0) return "";
    string res = "1";
    n--;        // We already initialized for n=1
    while (n--) 
    {   string cur = "";    // Parse (n-1)th result and write it to cur
        for (int i = 0; i < res.size(); i++) 
        {   int count = 0;
            char ch = res[i];
            while ((i < res.size()) && (res[i] == ch))
            {   count++;    
                i++;
            }
            i--;    // Very important. You need to shift back because for loop will increment anyway
            cur += to_string(count) + ch;
        }
        res = cur;
    }
    return res;
}