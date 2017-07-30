 //Given an array of integers, find if the array contains any duplicates. 
// Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.

// My solution 
bool containsDuplicate(vector<int>& nums) {
    map<int, int> ref;
    for (int i: nums)
    {   if (ref.find(i) == ref.end())
            ref[i]=0;
        else return true;
    }
    return false;
}

// Other solutions
len(nums) == len(set(nums))