// Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.

// DFS solution
class Solution {
public:
  unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> hash;
  
  UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) 
  {
     if (!node) return node;
     if(hash.find(node) == hash.end()) 
     {
         hash[node] = new UndirectedGraphNode(node -> label);
         for (auto x : node -> neighbors) 
              (hash[node] -> neighbors).push_back(cloneGraph(x));
     }
     return hash[node];
  }
}