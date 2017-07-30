/* 
Each letter in the magazine string can only be used once in your ransom note.

Note:
You may assume that both strings contain only lowercase letters.

canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true
*/

bool canConstruct(string ransomNote, string magazine) {
    
    map<char, int> m;
    for (int i = 0; i<magazine.size(); i++)
    {
        if (m.find(magazine[i]) == m.end()) m[magazine[i]]=1;
        else m[magazine[i]]++;
    }
    
    for (int i = 0; i<ransomNote.size(); i++)
    {
        if (m.find(ransomNote[i]) == m.end()) return false;
        else
        {
            if (m[ransomNote[i]] == 0) return false;
            m[ransomNote[i]]--;
        }
    }
    return true;
}
