/* 
Implement a basic calculator to evaluate a simple expression string.

The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

You may assume that the given expression is always valid.

Some examples:
"1 + 1" = 2
" 2-1 + 2 " = 3
"(1+(4+5+2)-3)+(6+8)" = 23
*/

// O(n) - time and space
int calculate(string s) {
    int i = 0, sign = 1, cur = 0, res = 0;
    stack<int> calc;
    while(i<s.size())
    {   if (isdigit(s[i]))
            cur = cur*10 + s[i] - '0';
        else
        {   res += sign * cur;
            cur = 0;
            if (s[i] == '-')    sign = -1;
            else if (s[i] == '+') sign = 1;
            else if (s[i] == '(')
            {   calc.push(res);
                calc.push(sign);
                res = 0;
                sign = 1;
            }
            else if (s[i] == ')')
            {   // Consider the sign
                res *= calc.top();
                calc.pop();
                
                // Consider the previous operand before '('
                res += calc.top();
                calc.pop();
            }
        }
        i++;
    }
    return res + sign*cur;
}