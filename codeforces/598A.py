q = int(input())
for i in range(q):
    a, b, n, S = map(int, input().split())
    k = S // n
    if (a < k and n * a + b >= S) or (a >= k and n * k + b >= S):
        print("YES")
    else:
        print("NO")