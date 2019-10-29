def bfs(adjacency_list, n, s):
    q = []
    used = [False for _ in range(n)]
    d, p = [None for _ in range(n)], [None for _ in range(n)]

    q.append(s)
    used[s] = True
    p[s] = -1
    while (len(q) > 0):
        v = q[0]
        q = q[1:]
        for u in adjacency_list[v]:
            if (!used[u]):
                used[u] = True 
                q.append(u)
                d[u] = d[v] + 1
                p[u] = v

