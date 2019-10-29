n, m = map(int, input().split())
cats = [int(x) for x in input().split()]

cats.insert(0, 0)

adj = [[] for _ in range(n+1)]

for i in range(1, n):
    u, v = map(int, input().split())
    adj[u].append(v)
    adj[v].append(u)


visited = [False for _ in range(n+1)]


def dfs(adj, cats, catCount, vertex, catMax):
    visited[vertex] = True
    for u in adj[vertex]:
        newCatCount = 1 + catCount if cats[u] > 0 else 0
        if not visited[u] and newCatCount <= catMax:
            dfs(adj, cats, newCatCount, u, catMax)


dfs(adj, cats, cats[1], 1, m)
res = 0

for i in range(len(adj)):
    if len(adj[i]) == 1 and visited[i] and i > 1:
        res += 1

print(res)
