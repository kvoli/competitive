a, b = map(int, input().split())

if b == a+1:
    print(a, b)
elif (a == 9 and b != 1) or (a + 1 < b) or (a > b and a != 9 and b != 1):
    print(-1)
else:
    if a == b:
        print("{}{} {}{}".format(a, 1, b, 2))
    elif a < b:
        print("{}{} {}{}".format(a, 9, b, 0))
    else:
        print("{} {}".format(a, 10))
    