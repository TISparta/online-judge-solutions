from collections import defaultdict
n, m = map(int,input().split())
d = defaultdict(list)
for it in range(n):
    d[input()].append(it+1)
for it in range(m):
    key = input()
    if d.__contains__(key):
        print(" ".join(str(idx) for idx in d[key]))
    else:
        print(-1)
