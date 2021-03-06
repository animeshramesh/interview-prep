/* Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution and you may not use the same element twice.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
*/


vector<int> twoSum(vector<int>& numbers, int target) {
    int left = 0, right = numbers.size()-1;
    vector<int> result;
    while (left <= right)
    {   int sum = numbers[left] + numbers[right];
        if (sum == target)
        {   result.push_back(left+1);
            result.push_back(right+1);
            return result;
        }
        else if (sum < target)
            left++;
        else
            right--;
    }
    return result;
}