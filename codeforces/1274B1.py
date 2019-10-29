from collections import Counter
t = int(input())

for i in range(t):
    n, k, d = map(int, input().split())
    shows = [int(x) for x in input().split()]
    current_shows = Counter(shows[:d])
    lowest = len(current_shows)
    current_len = lowest
    for j in range(d, n):
        delta = 0
        
        if current_shows[shows[j-d]] == 1:
            # print("removing " + str(shows[j-d]))
            delta -= 1
        
        w = Counter({shows[j-d]})
        current_shows -= w
        
        if current_shows[shows[j]] == 0:
            delta += 1
            # print("first addition of " + str(shows[j]))
        
        o = Counter({shows[j]})
        current_shows += o
       
        current_len += delta
        # print("current shows & length")
        # print(current_shows)
        # print(current_len)
        lowest = min(lowest, current_len)
        # print("*******************************************")
    print(lowest)


        