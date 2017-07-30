/* Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:
Given s = "hello", return "holle".

Example 2:
Given s = "leetcode", return "leotcede".

Note:
The vowels does not include the letter "y". */

string reverseVowels(string s) {
    auto p1 = s.begin(), p2 = s.end() - 1;
    string vowels = "aeiouAEIOU";
    while(p1 < p2) {
        while((vowels.find(*p1) == -1) && (p1 < p2)) p1++;
        while((vowels.find(*p2) == -1) && (p1 < p2)) p2--;
        if(p1 < p2) swap(*p1, *p2);
        p1++;
        p2--;
    }
    return s;
}