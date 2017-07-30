/* 
You are given a m x n 2D grid initialized with these three possible values.
-1 - A wall or an obstacle.
0 - A gate.
INF - Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INF as you may assume that the 
distance to a gate is less than INT_MAX.
Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.
For example, given the 2D grid:
INF  -1  0  INF
INF INF INF  -1
INF  -1 INF  -1
  0  -1 INF INF
After running your function, the 2D grid should be:
  3  -1   0   1
  2   2   1  -1
  1  -1   2  -1
  0  -1   3   4
Understand the problem:
It is very classic backtracking problem. We can start from each gate (0 point), and searching for its neighbors. 
We can either use DFS or BFS solution.

*/

// Time complexity - O(n^4)
int INF = INT_MAX;
void dfs_wag(vector<vector<int>>& r, int row, int col, int steps)
{
	if (row < 0 || row > r.size() - 1) return;
	if (col < 0 || col > r[0].size() - 1) return;
	if (r[row][col] == -1) return; // ignore wall

    // Important condition
	if (r[row][col] != INF && r[row][col] < steps) return;

	r[row][col] = steps;

	dfs_wag(r, row + 1, col, steps + 1);
	dfs_wag(r, row - 1, col, steps + 1);
	dfs_wag(r, row, col + 1, steps + 1);
	dfs_wag(r, row, col - 1, steps + 1);
}
void wallsAndGates(vector<vector<int>>& rooms) 
{

	for (int i = 0; i < rooms.size(); ++i) 
    {
		for (int j = 0; j < rooms[0].size(); ++j) 
        {   
            // DFS from gate
			if (rooms[i][j] == 0) 
				dfs_wag(rooms, i, j, 0);
			
		}
	}
}


// BFS Solution - O(N^4)
void wallsAndGates(vector<vector<int>>& rooms) {
    if(rooms.empty() || rooms[0].empty()) return;
    deque<pair<int,int>>dq;
    for(int i = 0; i < rooms.size(); i++)
        for(int j = 0; j < rooms[0].size(); j++)
            if(rooms[i][j] == 0) dq.push_back(make_pair(i,j));
    while(!dq.empty())
    {
        int r = dq.front().first;
        int c = dq.front().second;
        dq.pop_front();

        // up
        if(r>0 && rooms[r-1][c] == INT_MAX)
        {
            rooms[r-1][c] = rooms[r][c]+1;
            dq.push_back(make_pair(r-1,c));
        }
        
        // left
        if(c>0 && rooms[r][c-1] == INT_MAX)
        {
            rooms[r][c-1] = rooms[r][c]+1;
            dq.push_back(make_pair(r,c-1));
        }
        
        // down
        if(r+1<rooms.size() && rooms[r+1][c] == INT_MAX)
        {
            rooms[r+1][c] = rooms[r][c]+1;
            dq.push_back(make_pair(r+1,c));
        }
        
        // right
        if(c+1 < rooms[0].size() && rooms[r][c+1] == INT_MAX)
        {
            rooms[r][c+1] = rooms[r][c]+1;
            dq.push_back(make_pair(r,c+1));
        }
    }
}



