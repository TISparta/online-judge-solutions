n,m = map(int,input().split())
v = list(map(int,input().split()))
s1 = set(map(int,input().split()))
s2 = set(map(int,input().split()))
happiness = 0
for it in v:
    if it in s1: happiness += 1
    elif it in s2: happiness -= 1
print(happiness)
