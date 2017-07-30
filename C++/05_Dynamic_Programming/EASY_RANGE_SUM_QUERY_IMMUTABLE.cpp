//Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.


// Was thinking of precomputing a 2D array. But later realized that extra space was not needed.
class NumArray {
public:

    vector<int> ref;
    NumArray(vector<int> nums) {
        int s = 0;
        ref.push_back(s);
        for (int i = 0; i<nums.size(); i++)
        {   s+= nums[i];
            ref.push_back(s);
        }
    }
    
    int sumRange(int i, int j) {
        return ref[j+1] - ref[i];
    }
};