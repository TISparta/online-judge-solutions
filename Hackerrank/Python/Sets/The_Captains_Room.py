K = int(input())
d = dict()
for it in map(int,input().split()):
    if it not in d.keys():
        d[it] = 1
    else:
        d[it] += 1
for it in d:
    if d[it]!=K:
        print(it)
        break
