// Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the 
// product of all the elements of nums except nums[i].

// Solve it without division and in O(n).

// For example, given [1,2,3,4], return [24,12,8,6].

// Follow up:
// Could you solve it with constant space complexity? 
// (Note: The output array does not count as extra space for the purpose of space complexity analysis.)

// First, consider O(n) time and O(n) space solution.
// Key idea is to use two entities.
// For each elements, get the product of all elements before it and the product of all elements after it. 
vector<int> productExceptSelf(vector<int>& nums) {
    int n=nums.size();
    vector<int> fromBegin(n);
    fromBegin[0]=1;
    vector<int> fromLast(n);
    fromLast[0]=1;
    
    for(int i=1;i<n;i++){
        fromBegin[i]=fromBegin[i-1]*nums[i-1];
        fromLast[i]=fromLast[i-1]*nums[n-i];
    }
    
    vector<int> res(n);
    for(int i=0;i<n;i++){
        res[i]=fromBegin[i]*fromLast[n-1-i];
    }
    return res;
}

// We just need to change the two vectors to two integers and note that we should do multiplying operations 
// for two related elements of the results vector in each loop.
vector<int> productExceptSelf(vector<int>& nums) 
{
    int n=nums.size();
    int fromBegin=1;
    int fromLast=1;
    vector<int> res(n,1);
    
    for(int i=0;i<n;i++)
    {
        res[i]*=fromBegin;
        fromBegin*=nums[i];
        res[n-1-i]*=fromLast;
        fromLast*=nums[n-1-i];
    }
    return res;
}
