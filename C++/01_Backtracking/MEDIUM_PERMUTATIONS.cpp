 vector<vector<int> > permute(vector<int> &num) 
 {
    vector<vector<int> > result;
    
    permuteRecursive(result, 0, num);
    return result;
}

// permute num[begin..end]
// invariant: num[0..begin-1] have been fixed/permuted
void permuteRecursive(vector<vector<int> > &result, int begin, vector<int> &num)	
{
	if (begin >= num.size()) 
	{
	    // one permutation instance
	    result.push_back(num);
	    return;
	}
	
	for (int i = begin; i < num.size(); i++) 
	{
	    swap(num[begin], num[i]);
	    permuteRecursive(num, begin + 1, result);
	    // reset
	    swap(num[begin], num[i]);
	}
}