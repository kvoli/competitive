import re
s = input()
for i in range(0 , 1000 , 8):
    a = '.*'.join([''] + list(str(i)) + [''])
    if  re.search(a , s) :
        print("YES")
        print(i)
        exit()
print("NO")