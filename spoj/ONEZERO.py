

def multiple(k):
    
    solved = False
    i = 1
    allowed = set('01')

    while(not solved):
        
        x = str(k * i)
        if set(x).issubset(allowed):
            return x
        else:
            i += 1

n = int(input())
res = []
for i in range(n):
    print(multiple(int(input())))


