rs = 0
ls = 0
res = 0
for i in s:
    if i == 'R':
        rs += 1
    else:
        ls += 1
    if rs == ls:
        res += 1
