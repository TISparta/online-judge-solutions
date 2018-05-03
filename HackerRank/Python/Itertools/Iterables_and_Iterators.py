from itertools import combinations
input()
x = list(combinations(input().split(),int(input())))
print(sum("a" in it for it in x)/len(x))
