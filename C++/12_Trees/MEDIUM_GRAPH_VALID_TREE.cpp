/* To tell whether a graph is a valid tree, we have to:

Make sure there is no cycle in the graph - this has to be a none-cyclic graph;
Make sure every node is reached - this has to be a connected graph;
Reference: https://en.wikipedia.org/wiki/Tree_(graph_theory)

Solution:

To test cyclic, we can make an array for each node (as array index), and the array will store the parent of the node (as array index). 
Every time we fetch a new pair of nodes, we trace the root node (the deepest parent node) of these two nodes, if it has the same root, then is will be a cycle; 
otherwise, we set the parent of second node to be the first node;

After we make sure there is node cycle in the graph, we simple test if there is enough edges to make this graph connected.

*/

// Union find solution
bool validTree(int n, vector<pair<int, int>>& edges) {
    vector<int> nodes(n,0);
    for(int i=0; i<n; i++) nodes[i] = i;
    for(int i=0; i<edges.size(); i++)
    {
        int f = edges[i].first;
        int s = edges[i].second;
        while(nodes[f]!=f) f = nodes[f];
        while(nodes[s]!=s) s = nodes[s];
        if(nodes[f] == nodes[s]) return false;
        nodes[s] = f;
    }
    return edges.size() == n-1;
}

vector<vector<int>> next;
    
bool validTree(int n, vector<pair<int, int>>& edges) {
    if (n - edges.size() != 1) return false;
    makeGraph(n, edges);
    return connected(n, edges);
}

// Making an adjacency list
void makeGraph(int n, vector<pair<int, int>>& edges) {
    next.resize(n);
    for (auto& e : edges)
        next[e.first].push_back(e.second), next[e.second].push_back(e.first);
}

bool connected(int n, vector<pair<int, int>>& edges) {
    vector<int> visited(n);
    queue<int> q; q.push(0); visited[0] = 1;
    int count = 0;
    while (!q.empty()) {
        int x = q.front(); q.pop(); ++count;
        for (int nxt : next[x]) {
            if (!visited[nxt]) q.push(nxt), visited[nxt] = 1;
        }
    }
    return count == n;
}