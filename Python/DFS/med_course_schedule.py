"""
Trick is to keep track of current path.

Time: O(V+E)
Space: O(V+E)
"""

from collections import defaultdict
class Solution:

    def dfs_cycle(self, node):

        self.visited[node]=True
        self.current_path[node]=True

        for neighbour in list(self.graph[node]):
            if not self.visited[neighbour]:
                if self.dfs_cycle(neighbour):
                    return True
            elif self.current_path[neighbour]:
                return True

        self.current_path[node]=False
        return False

    def canFinish(self, numCourses, prerequisites):
        self.graph = defaultdict(set)

        for p in prerequisites:
            src, dest = p
            self.graph[src].add(dest)

        self.visited = [False]*numCourses
        self.current_path =  [False]*numCourses

        for i in range(numCourses):
            if not self.visited[i] and self.dfs_cycle(i):
                return False

        return True
