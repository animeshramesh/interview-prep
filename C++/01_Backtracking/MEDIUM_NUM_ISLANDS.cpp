// Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

// Example 1:

// 11110
// 11010
// 11000
// 00000
// Answer: 1

// Example 2:

// 11000
// 11000
// 00100
// 00011
// Answer: 3

// My solution
class Solution {
public:
    
    // you don't need the extra visited 2D matrix. You can just make grid[i][j]='0'
    // This is a DFS solution
    bool isIsland(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j)
    {
        if(i<0 || j<0 || i >=grid.size() || j>=grid[0].size()) return false;
        
        if (grid[i][j]=='1' && !visited[i][j])
        {
            visited[i][j]=true;
            bool left = isIsland(grid, visited, i, j-1);
            bool right = isIsland(grid, visited, i, j+1);
            bool up = isIsland(grid, visited, i-1, j);
            bool down = isIsland(grid, visited, i+1, j);
            return true;
            
        }
        else return false;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        int islands = 0;
        if (grid.size() == 0) return 0;
        int r = grid.size(), c = grid[0].size();
        
        // Initialize visited
        vector<vector<bool>> visited;
        for (int i = 0; i<r; i++)
        {
            vector<bool> row(c, false);
            visited.push_back(row);   
        }
        
        for (int i = 0; i<grid.size(); i++)
        {
            for (int j = 0; j<grid[0].size(); j++)
            {
                if (isIsland(grid, visited, i, j)) islands++;
            }
        }
        return islands;
    }
};

