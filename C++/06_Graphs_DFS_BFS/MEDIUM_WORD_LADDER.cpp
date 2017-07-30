/* Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time.
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
For example,

Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log","cog"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.*/


// Solution

/* Well, this problem has a nice BFS structure.

Let's see the example in the problem statement.

start = "hit"

end = "cog"

dict = ["hot", "dot", "dog", "lot", "log"]

Since only one letter can be changed at a time, if we start from "hit", we can only change to those words which have only one 
different letter from it, like "hot". Putting in graph-theoretic terms, we can say that "hot" is a neighbor of "hit".

The idea is simpy to begin from start, then visit its neighbors, then the non-visited neighbors of its neighbors... 
Well, this is just the typical BFS structure.

To simplify the problem, we insert end into dict. Once we meet end during the BFS, we know we have found the answer. 
We maintain a variable dist for the current distance of the transformation and update it by dist++ after we finish a round of BFS search 
(note that it should fit the definition of the distance in the problem statement). 
Also, to avoid visiting a word for more than once, we erase it from dict once it is visited.

*/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        // Create word dictionary
        unordered_set<string> wordDict;
        for (string word : wordList) wordDict.insert(word);

        // No path if endWord not in wordDict
        if (wordDict.find(endWord) == wordDict.end()) return 0;
        
        int dist = 1;
        queue<string> q;
        q.push(beginWord);
        
        while (!q.empty()) 
        {   int num = q.size();
            for (int i = 0; i < num; i++) 
            {   string word = q.front();
                q.pop();
                if (word == endWord) return dist;
                addNeighbours(word, wordDict, q);
            }
            dist++;
        }
        return 0;
    }
        
    private:
    void addNeighbours(string word, unordered_set<string>& wordDict, queue<string>& q) {
        wordDict.erase(word);   // Important!
        for (int i = 0; i < (int)word.length(); i++) 
        {   char letter = word[i];
            // Keep changing one letter at a time and see whether there's a word.
            // Length is the same. So it makes it easier
            for (int j = 0; j < 26; j++) 
            {   word[i] = 'a' + j;
                if (wordDict.find(word) != wordDict.end()) 
                {   q.push(word);
                    wordDict.erase(word);
                }
            }
            word[i] = letter;
        } 
    }
    
};

// The above code can still be speeded up if we also begin from end. 
// Once we meet the same word from start and end, we know we are done. 
// Note that the use of two pointers phead and ptail save a lot of time. 
// At each round of BFS, depending on the relative size of head and tail, we point phead to the smaller set to reduce the running time.

class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
        unordered_set<string> head, tail, *phead, *ptail;
        head.insert(beginWord);
        tail.insert(endWord);
        int dist = 2;
        while (!head.empty() && !tail.empty()) 
        {
            if (head.size() < tail.size()) 
            {
                phead = &head;
                ptail = &tail;
            }
            else 
            {
                phead = &tail; 
                ptail = &head;
            }
            unordered_set<string> temp; 
            for (auto itr = phead -> begin(); itr != phead -> end(); itr++) 
            {
                string word = *itr;
                wordDict.erase(word);
                for (int p = 0; p < (int)word.length(); p++) 
                {
                    char letter = word[p];
                    for (int k = 0; k < 26; k++) 
                    {
                        word[p] = 'a' + k;
                        if (ptail -> find(word) != ptail -> end())
                            return dist;
                        if (wordDict.find(word) != wordDict.end()) 
                        {
                            temp.insert(word);
                            wordDict.erase(word);
                        }
                    }
                    word[p] = letter;
                }
            }
            dist++;
            swap(*phead, temp);
        }
        return 0; 
    }
};