N, X = map(int,input().split())
v = list()
for it in range(X):
    v.append(list(map(float,input().split())))
print("\n".join([str(sum(it)/X) for it in zip(*v)]))
