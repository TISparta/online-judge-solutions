from itertools import product
A = input().split()
B = input().split()
print(" ".join("(%s, %s)" %(a,b) for a,b in product(A,B)))
