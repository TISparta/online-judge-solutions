from itertools import groupby
print(" ".join("(%d, %d)" %(len(list(b)),int(a)) for a,b in groupby(input())))
