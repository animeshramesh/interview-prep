/*
The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given two integers x and y, calculate the Hamming distance.

Note:
0 ≤ x, y < 2^31.
*/

// Find XOR(x,y) and find the number of 1s in it.
int hammingDistance(int x, int y) {
    int res = x^y;
    int c = 0;
    while (res)
    {
        c+= res%2;
        res = res >> 1;
    }
    return c;
}