from itertools import permutations
s,k = input().split()
print("\n".join("".join(it) for it in permutations(sorted(s),int(k))))
