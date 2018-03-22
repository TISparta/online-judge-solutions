from itertools import combinations
s,k = input().split()
print("\n".join("".join(it) for n in range(1,int(k)+1) for it in combinations(sorted(s),n)))
