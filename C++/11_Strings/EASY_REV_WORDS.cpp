// Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

string reverseWords(string s) {
    string rev("");
    string word("");
    
    for (int i = 0; i<s.size(); i++)
    {
        if (s[i] == ' ')
        {   reverse(word.begin(),word.end());
            rev +=  word;
            rev += ' ';
            word = "";
        }
        else word += s[i];
    }    
    if(word.size() > 0)
    {
        reverse(word.begin(),word.end());
        rev+=word;
    }
    return rev;
}