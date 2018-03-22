from itertools import product
K, M = map(int,input().split())
v = list()
for it in range(K):
    v.append(list(map(int,input().split()))[1:])
print(max(sum(i*i for i in it)%M for it in list(product(*v))))
