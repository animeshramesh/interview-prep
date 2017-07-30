// Given a List of words, return the words that can be typed using letters of alphabet on only one row's of American keyboard

bool isInString(string row, string word)
{   bool isIn = true;
    for (int i = 0; i<word.size(); i++)
    {
        if (row.find(word[i]) == -1)
        {
            isIn = false;
            break;
        }
    }
    return isIn;
}

vector<string> findWords(vector<string>& words) {
    string row1 = "qwertyuiopQWERTYUIOP";
    string row2 = "asdfghjklASDFGHJKL";
    string row3 = "zxcvbnmZXCVBNM";
    
    vector<string> res;
    
    for (int i = 0; i<words.size(); i++)
    {   
        if (isInString(row1, words[i]))
            res.push_back(words[i]);
        else if (isInString(row2, words[i]))
            res.push_back(words[i]);
        else if (isInString(row3, words[i]))
            res.push_back(words[i]);
        else if (words[i].size() == 0)
            res.push_back(words[i]);
    }
    return res;
}