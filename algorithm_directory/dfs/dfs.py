def dfs(adj, n):
    visited = [False for _ in range(n)]
    
    def dfs_explore(v):
        visited[v] = True
        for u in adj[v]:
            if !visited[u]:
                dfs_explore(u)

