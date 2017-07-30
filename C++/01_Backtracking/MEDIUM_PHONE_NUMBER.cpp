/* 
For number above 234. Do you see any pattern? Yes, we notice that the last character always either G,H or I and 
whenever it resets its value from I to G, the digit at the left of it gets changed.
Similarly whenever the second last alphabet resets its value, the third last alphabet gets changes and so on. 
First character resets only once when we have generated all words. This can be looked from other end also. 
That is to say whenever character at position i changes, character at position i+1 goes through all possible characters 
and it creates ripple effect till we reach at end.
Since 0 and 1 don’t have any characters associated with them. we should break as there will no iteration for these digits.
Let’s take the second approach as it will be easy to implement it using recursion. We go till the end and come back one by one. 
Perfect condition for recursion. let’s search for base case.
When we reach at the last character, we print the word with all possible characters for last digit and return. Simple base case.

*/


// at most O(n*4^n), where n is the number of digits
// Backtracking solution
vector<string> letterCombinations(string digits) {
    vector<string> res;
    if(digits.size() == 0) return res;
    string temp;
    vector<vector<char>> table{{'0'}, {'1'}, {'a','b','c'}, {'d','e','f'}, {'g','h','i'}, {'j','k','l'}, {'m','n','o'}, {'p','q','r','s'}, {'t','u','v'}, {'w','x','y','z'}};
    
    backtracking(table, res, temp, 0, digits);
    return res;
}

void backtracking(vector<vector<char>>& table, vector<string>& res, string& temp, int index, string& digits){
    int digit = digits[index] - '0';

    if(index == digits.size())
        res.push_back(temp);
    else
    {
        for(int i = 0; i < table[digit].size(); i++)
        {
            temp += table[digit][i];
            backtracking(table, res, temp, index+1, digits);
            temp.pop_back(); // This is confusing. Make sure you understand why pop_back is needed. Its needed to backtrack.
        }
    }
        
}


// Iterative BFS solution
vector<string> letterCombinations(string digits) {
    vector<string> res;
    string charmap[10] = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    res.push_back("");
    for (int i = 0; i < digits.size(); i++)
    {
        vector<string> tempres;
        string chars = charmap[digits[i] - '0'];
        for (int c = 0; c < chars.size();c++)
            for (int j = 0; j < res.size();j++)
                tempres.push_back(res[j]+chars[c]);
        res = tempres;
    }
    return res;
}