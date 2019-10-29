def solve(points, k):
    points.sort(key=lambda x : (x[0]** 2 + x[1]**2))
    print(points[:k])

solve([[3,3],[5,-1],[-2,4]], 2)