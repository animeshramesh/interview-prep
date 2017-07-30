int bSearch(int target, vector<int> & nums, int start, int end)
{   if (start > end) return -1;
    int mid = (start+end)/2;
    if (nums[mid]==target) return mid;
    if (nums[mid]<target) return bSearch(target, nums, mid+1, end);
    else return bSearch(target, nums, start, mid-1);
}

int search(vector<int>& nums, int target) 
{
    
    if (nums.empty()) return -1;
    
    // Binary search to find pivot
    int n = nums.size();
    int start = 0, end = n-1;        
    while(start<end)
    {   int mid = (start+end)/2;
        if (nums[mid]>nums[end]) start = mid + 1;
        else end = mid;
    }
    
    int pivot = start;
    start = 0, end = n-1;
    
    if (target<=nums.back() && target >= nums[pivot])
        return bSearch(target, nums, pivot, n-1);
    else return bSearch(target, nums, 0, pivot-1);
}