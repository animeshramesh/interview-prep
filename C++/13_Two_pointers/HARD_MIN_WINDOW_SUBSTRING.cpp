/* 
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the empty string "".

If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.
*/

/* 
1- First check if length of string is less than
   the length of given pattern, if yes
       then "no such window can exist ".
2- Store the occurrence of characters of given 
   pattern in a hash_pat[].
3- Start matching the characters of pattern with 
   the characters of string i.e. increment count 
   if a character matches
4- Check if (count == length of pattern ) this 
   means a window is found
5- If such window found, try to minimize it by 
   removing extra characters from beginning of
   current window.
6- Update min_length.
7- Print the minimum length window.
*/


// Function to find smallest window containing
// all characters of 'pat'
string findSubString(string str, string pat)
{
    int len1 = str.length();
    int len2 = pat.length();
 
    // check if string's length is less than pattern's
    // length. If yes then no such window can exist
    if (len1 < len2)
    {
        //cout << "No such window exists";
        return "";
    }
 
    int hash_pat[no_of_chars] = {0};
    int hash_str[no_of_chars] = {0};
 
    // store occurrence ofs characters of pattern
    for (int i = 0; i < len2; i++)
        hash_pat[pat[i]]++;
 
    int start = 0, start_index = -1, min_len = INT_MAX;
 
    // start traversing the string
    int count = 0; // count of characters
    for (int j = 0; j < len1 ; j++)
    {
        // count occurrence of characters of string
        hash_str[str[j]]++;
 
        // If string's char matches with pattern's char
        // then increment count
        if (hash_pat[str[j]] != 0 &&
            hash_str[str[j]] <= hash_pat[str[j]] )
            count++;
 
        // if all the characters are matched
        if (count == len2)
        {
            // Try to minimize the window i.e., check if
            // any character is occurring more no. of times
            // than its occurrence in pattern, if yes
            // then remove it from starting and also remove
            // the useless characters.
            while ( hash_str[str[start]] > hash_pat[str[start]]
                || hash_pat[str[start]] == 0)
            {
 
                if (hash_str[str[start]] > hash_pat[str[start]])
                    hash_str[str[start]]--;
                start++;
            }
 
            // update window size
            int len_window = j - start + 1;
            if (min_len > len_window)
            {
                min_len = len_window;
                start_index = start;
            }
        }
    }
 
    // If no window found
    if (start_index == -1)
    {
        //cout << "No such window exists";
        return "";
    }
 
    // Return substring starting from start_index
    // and length min_len
    return str.substr(start_index, min_len);
}



// Another solution
string minWindow(string S, string T) 
{
    string result;
    if(S.empty() || T.empty())
        return result;
    
    unordered_map<char, int> counts;    // Character count of template
    unordered_map<char, int> window;    // Character count present in window

    // Get counts of template!!
    for(int i = 0; i < T.length(); i++)
        counts[T[i]]++;
    
    int minLength = INT_MAX;
    int letterCounter = 0;

    for(int slow = 0, fast = 0; fast < S.length(); fast++)
    {
        char c = S[fast];
        if(counts.find(c) != counts.end())
        {
            window[c]++;
            if(window[c] <= counts[c])
                letterCounter++;
            
        }

        if(letterCounter >= T.length())
        {   // If its an unnecessary character
            // Or an extra character
            while(counts.find(S[slow]) == counts.end() || window[S[slow]] > counts[S[slow]])
            {
                window[S[slow]]--;
                slow++;
            }
            if(fast - slow + 1 < minLength)
            {
                minLength = fast - slow + 1;
                result = S.substr(slow, minLength);
            }
        }
    }
    return result;
}