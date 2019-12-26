t = int(input())
for i in range(t):
    wins = 0
    n = int(input())
    a, b, c = map(int, input().split())
    s = input()
    res = [None for _ in range(n)]
    for i in range(n):
        if s[i] == 'R' and b > 0:
            b -= 1
            wins += 1
            res[i] = 'P'
    for i in range(n):
        if s[i] == 'P' and c > 0:
            c -= 1
            wins += 1
            res[i] = 'S'
    for i in range(n):
        if s[i] == 'S' and a > 0:
            a -= 1
            wins += 1
            res[i] = 'R'
    for i in range(n):
        if not res[i]:
            if a > 0:
                res[i] = 'R'
                a -= 1
            elif b > 0:
                res[i] = 'P'
                b -= 1
            else:
                res[i] = 'S'
                c -= 1
    if (wins > (-(-n//2))):
        print("YES")
        print(''.join(res))
    else:
        print("NO")
    