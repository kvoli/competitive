n, m = map(int, input().split())


def is_pal(s):
    return s == s[::-1]

seen = set()
best_single = ""
res = ""

for i in range(n):
    s = input()
    if s[::-1] in seen:
        res = res + s
    elif is_pal(s) and len(s) > len(best_single):
        best_single = s
    seen.add(s)

print(len(res)*2 + len(best_single))
print(res + best_single + res[::-1])
