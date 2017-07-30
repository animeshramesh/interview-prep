/*
Reverse digits of an integer. The input is assumed to be a 32-bit signed integer. 
Your function should return 0 when the reversed integer overflows.

Examples:
123 -> 321
0 -> 0
10 -> 1
-123 -> -321
*/

int reverse(int x) {
    long long result = 0;
    int i = 1;
    while (x)
    {
        result = result*10 + x%10;
        x/=10;
    }
    if (abs(result) > INT_MAX)
        return 0;
    return result;
}