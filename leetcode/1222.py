def qs(queens, kings):

    def distance(p1, p2):
        return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1])
    
    def diagonal(p1, p2):
        return abs(p1[0] - p2[0]) == abs(p1[1] - p2[1])
    
    def diagType(p1, p2):
        if diagonal(p1, p2):
            if(p1[0] > p2[0]):
                return 4 if p1[1] > p2[1] else 1
            else:
                return 3 if p1[1] > p2[1] else 2
        if p1[0] == p2[0]:
            return 5 if p1[1] > p2[1] else 6
        if p1[1] == p2[1]:
            return 7 if p1[0] > p2[0] else 8
        return -1
    
    bests = [[100,100] for _ in range(8)]
    for q in queens:
        v, dist = diagType(kings, q), distance(kings, q)
        if v > 0 and dist < distance(kings, bests[v-1]):
            bests[v-1] = q
        
    
    return (filter(lambda x: x != [100,100], bests))

print(qs([[0,1],[1,0],[4,0],[0,4],[3,3],[2,4]], [0,0]))