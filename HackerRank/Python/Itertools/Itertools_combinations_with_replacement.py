from itertools import combinations_with_replacement as cwr
s,k = input().split()
print("\n".join("".join(it) for it in cwr(sorted(s),int(k))))
