/* 

There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.

There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.

For example:

2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1]

4, [[1,0],[2,0],[3,1],[3,2]]
There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0. So one correct course order is [0,1,2,3]. Another correct ordering is[0,2,1,3].

Note:
The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.
*/

// Topological sort using BFS
vector<int> findOrder(int numCourses, vector<pair<int, int>>& prereq) {
    // Make graph
    vector<vector<int>> graph(numCourses);
    for (auto p: prereq)
        graph[p.second].push_back(p.first);
    
    // Compute in-degree
    vector<int> inDegree(numCourses, 0); // Contains node-ids which have zero
    for (auto node:graph)
    {   for(auto neighbour : node)
            inDegree[neighbour]++;
    }
    
    // Push 0 in-degree nodes to Queue
    queue<int> q;
    for (int i = 0; i<numCourses; i++)
        if(inDegree[i]==0)
            q.push(i);
    
    vector<int> result;
    while(!q.empty())
    {   int node = q.front();
        q.pop();
        for (int neighbour : graph[node])
        {   inDegree[neighbour]--;
            if (inDegree[neighbour] == 0)
                q.push(neighbour);
        }
        result.push_back(node);
    }   

    // This checks for acyclic graph
    if (result.size() == numCourses)
        return result;
    else 
    {   result.clear();
        return result;
    }
    
}