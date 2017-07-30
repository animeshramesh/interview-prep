
class Solution
{	string alienOrder(vector<string>& words) 
	{
          if (words.size() == 1) return words[0];
          graph g = make_graph(words);
          return toposort(g);	// See COURSE_SCHEDULE_II for toposort using BFS
    }

	private:
		typedef unordered_map<char, unordered_set<char>> graph;
     
		 graph make_graph(vector<string>& words) 
		 {
		     graph g;
		     int n = words.size();
		     for (int i = 1; i < n; i++) 
		     {
		         bool found = false;
		         string word1 = words[i - 1], word2 = words[i];
		         int m = word1.length(), n = word2.length(), l = max(m, n);
		         for (int j = 0; j < l; j++) 
		         {
		             if (j < m && g.find(word1[j]) == g.end())
		                 g[word1[j]] = unordered_set<char>();

		             if (j < n && g.find(word2[j]) == g.end())
		                 g[word2[j]] = unordered_set<char>();

		             // Consider only the 1st change
		             if (j < m && j < n && word1[j] != word2[j] && !found) 
		             {
		                 g[word1[j]].insert(word2[j]);
		                 found = true;
		             }
		         }
		     }
		     return g;
		 }
}
