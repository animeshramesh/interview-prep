/* Given a word, you need to judge whether the usage of capitals in it is right or not.

We define the usage of capitals in a word to be right when one of the following cases holds:

All letters in this word are capitals, like "USA".
All letters in this word are not capitals, like "leetcode".
Only the first letter in this word is capital if it has more than one letter, like "Google".
Otherwise, we define that this word doesn't use capitals in a right way.
Example 1:
Input: "USA"
Output: True
Example 2:
Input: "FlaG"
Output: False
Note: The input will be a non-empty word consisting of uppercase and lowercase latin letters.
*/

bool detectCapitalUse(string word) {
    
    int num_caps = 0, num_small = 0, s = word.size();
    for (auto c:word)
    {	if (isupper(c)) num_caps++;
        else num_small++;
    }
    return (num_caps == s || num_small == s || (num_small == s - 1 && isupper(word[0]))); 
}