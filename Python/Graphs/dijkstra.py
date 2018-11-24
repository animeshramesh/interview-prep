
from collections import defaultdict
from heapq import *


"""
Basically a greedy BFS using a minheap.
Time -> O(E+V)log(V)
Space -> O(V) in heap
"""
def dijkstra(edges, f, t):
    g = defaultdict(list)
    for l,r,c in edges:
        g[l].append((c,r))

    q, seen, mins = [(0,f,[]], set(), {f: 0}
    while q:
        (cost,v1,path) = heappop(q)
        if v1 not in seen:
            seen.add(v1)
            path += v1
            if v1 == t: return (cost, path)

            for c, v2 in g[v1]:
                if v2 in seen: continue
                prev_cost = mins[v2]
                new_cost = cost + c
                if not prev_cost or new_cost < prev_cost:
                    mins[v2] = new_cost
                    heappush(q, (new_cost, v2, path))

    return float("inf")
