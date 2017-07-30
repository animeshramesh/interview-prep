/* Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.

*/


// My solution - TLE. I missed out toggling the visited flag
bool outOfBounds(vector<vector<char>>& board, int i, int j)
{
    if (i < 0 || j < 0) return true;
    if (i>=board.size() || j >= board[0].size()) return true;
    return false;
}

bool backtrack(vector<vector<char>>& board, int i, int j, string word, int k)
{   
    if (outOfBounds(board, i, j)) return false;
    if (board[i][j]==char(word[k]))
    {   
        if (k == word.size()-1) return true;
        
        char t=board[i][j];
		board[i][j]='\0';
        
        bool left = backtrack(board, i, j-1, word, k+1);
        bool right = backtrack(board, i, j+1, word, k+1);
        bool up = backtrack(board, i-1, j, word, k+1);
        bool down = backtrack(board, i+1, j, word, k+1);
        
        board[i][j]=t;
        return left || right || up || down;
    }
    return false;
}

bool exist(vector<vector<char>>& board, string word) {
    for (int i = 0; i<board.size(); i++)
    {
        for (int j = 0; j<board[0].size(); j++)
            if (backtrack(board, i, j, word, 0))
                return true;
    }
    return false;
}

// Optimal solution
// O(m*n*k)
bool exist(vector<vector<char>>& board, string word) {
    for (int i = 0; i < board.size(); i++) 
    {
        for (int j = 0; j < board[0].size(); j++) 
        {
            if(exist(board, i, j, word, 0)) return true;
        }
    }
    return false;
}

bool exist(vector<vector<char>>& board, int i, int j, string word, int k) {
    if(k >= word.length()) return true;
    if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) return false;
    if (board[i][j] == word[k++]) 
    {
        char c = board[i][j];
        board[i][j] = '#';
        bool left = exist(board, i, j-1, word, k+1);
        bool right = exist(board, i, j+1, word, k+1);
        bool up = exist(board, i-1, j, word, k+1);
        bool down = exist(board, i+1, j, word, k+1);
        board[i][j] = c;
        return left || right || up || down;
    }
    return false;
}