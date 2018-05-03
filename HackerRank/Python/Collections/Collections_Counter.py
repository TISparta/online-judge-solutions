from collections import Counter
input()
v = Counter(list(map(int,input().split())))
ans = 0
for q in range(int(input())):
    idx, value = map(int,input().split())
    if v[idx]:
        ans += value
        v[idx] -= 1
print(ans)
