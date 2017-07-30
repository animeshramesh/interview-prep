/* 
Given two sparse matrices A and B, return the result of AB.

You may assume that A's column number is equal to B's row number.

Example:

A = [
  [ 1, 0, 0],
  [-1, 0, 3]
]

B = [
  [ 7, 0, 0 ],
  [ 0, 0, 0 ],
  [ 0, 0, 1 ]
]


     |  1 0 0 |   | 7 0 0 |   |  7 0 0 |
AB = | -1 0 3 | x | 0 0 0 | = | -7 0 3 |
                  | 0 0 1 |
*/


// Normal Matrix Multiplication
// m x n times n x q
for(i = 0; i < m; ++i)
{	for(j = 0; j < q; ++j)
    {	c[i][j] = 0;
        for(k = 0; k < n; ++k)
            c[i][j] += a[i][k] * b[k][j];
	}
}

// https://discuss.leetcode.com/topic/72871/54ms-detailed-summary-of-easiest-java-solutions-beating-99-9/2
// Hash Table method
// Need to memorize indices
vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) 
{   int m = A.size(), q = B[0].size();
    vector<vector<int>> out(A.size(), vector<int>(q, 0));
    unordered_map<int, vector<int>> BNonZeroIndexes;  // row wise
   	
   	// Get all non-zero indices of matrix B
   	for(int i = 0; i < B.size(); i++) 
   	{	BNonZeroIndexes[i] = {};
    	for(int k = 0; k < q; k++) 
        	if(B[i][k])  
           		BNonZeroIndexes[i].push_back(k);
        
    }
    
    // Multiply with A
    for(int i = 0; i < m; i++) 
    {	for(int k = 0; k < A[0].size(); k++) 
    	{	if(A[i][k] != 0) 
    		{	for(int j : BNonZeroIndexes[k]) 
    			{ 	//In Row K, Iterate only over indexes that has non-zero values.
                     out[i][j] += A[i][k] * B[k][j];
                }
            }
        }
    }
    
    return out;
}