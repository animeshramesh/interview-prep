/* Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2.

Note:

The length of both num1 and num2 is < 110.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.
*/

// http://www.geeksforgeeks.org/multiply-large-numbers-represented-as-strings/
// // O(m*n)
string multiply(string num1, string num2) {
    int n1 = num1.size();
    int n2 = num2.size();
    if (n1 == 0 || n2 == 0)
       return "0";

    // will keep the result number in vector
    // in reverse order
    vector<int> result(n1 + n2, 0);

    // Below two indexes are used to find positions
    // in result. 
    int i_n1 = 0; 
    int i_n2 = 0; 

    // Go from right to left in num1
    for (int i=n1-1; i>=0; i--)
    {
        int carry = 0;
        int n1 = num1[i] - '0';

        // To shift position to left after every
        // multiplication of a digit in num2
        i_n2 = 0; 

        // Go from right to left in num2             
        for (int j=n2-1; j>=0; j--)
        {
            // Take current digit of second number
            int n2 = num2[j] - '0';

            // Multiply with current digit of first number
            // and add result to previously stored result
            // at current position. 
            int sum = n1*n2 + result[i_n1 + i_n2] + carry;

            // Carry for next iteration
            carry = sum/10;

            // Store result
            result[i_n1 + i_n2] = sum % 10;

            i_n2++;
        }

        // store carry in next cell
        if (carry > 0)
            result[i_n1 + i_n2] += carry;

        // To shift position to left after every
        // multiplication of a digit in num1.
        i_n1++;
    }

    // ignore '0's from the right
    int i = result.size() - 1;
    while (i>=0 && result[i] == 0)
       i--;

    // If all were '0's - means either both or
    // one of num1 or num2 were '0'
    if (i == -1)
       return "0";

    // generate the result string
    string s = "";
    while (i >= 0)
        s += std::to_string(result[i--]);

    return s;
}

// Following soluiton without any extra space
// O(m*n)
string multiply(string num1, string num2) 
{
    string sum(num1.size() + num2.size(), '0');
    
    // Read string1 from reverse
    for (int i = num1.size() - 1; i>=0; i--) 
    {
        int carry = 0;
        int n1 = (int)num1[i] - '0';
        for (int j = num2.size() - 1; 0 j>=0; j--) 
        {   int n2 = (int)num2[j] - '0';
            int tmp = (sum[i + j + 1] - '0') + n1 * n2 + carry;
            sum[i + j + 1] = (tmp % 10) + '0';
            carry = tmp / 10;
        }
        sum[i] += carry;
    }
    
    size_t startpos = sum.find_first_not_of("0");
    if (string::npos != startpos) {
        return sum.substr(startpos);
    }
    return "0";
}