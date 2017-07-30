// Given a positive integer num, write a function which returns True if num is a perfect square else False.

bool isPerfectSquare(int num)
{   long long l = 0, r = num;
    while (l <= r) {
        long long mid = (l + r) / 2;
        long long sq = mid * mid;
        if (sq > num) r = mid - 1;
        else if (sq < num) l = mid + 1;
        else return true;
    }
    return false;
}