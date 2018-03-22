input()
v = input().split()
print(any(it==it[::-1] for it in v) and all(int(it)>0 for it in v))
