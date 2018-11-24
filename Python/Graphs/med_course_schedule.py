def canFinish(self, n, pres):
    from collections import deque
    ind = [[] for _ in xrange(n)]  # indegree
    oud = [0] * n  # outdegree
    for p in pres:
        oud[p[0]] += 1
        ind[p[1]].append(p[0])
    dq = deque()
    for i in xrange(n):
        if oud[i] == 0:
            dq.append(i)
    k = 0
    while dq:
        node = dq.popleft()
        k += 1
        for neighbour in ind[node]:
            oud[neighbour] -= 1
            if oud[neighbour] == 0:
                dq.append(neighbour)
    return k == n
