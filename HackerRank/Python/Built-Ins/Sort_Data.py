N, M = map(int,input().split())
v = list()
for it in range(N):
    v.append(list(map(int,input().split())))
k = int(input())
print("\n".join(" ".join(str(i) for i in it) for it in sorted(v,key=lambda u: u[k])))
