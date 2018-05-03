
# Execution time : 0.093482 seconds

# Solution Explanation
# We can use the power of Python's built-in and implement it.


import time
width = 40
from functools import reduce

def solution():
    s, it = '', 0
    while len(s)<=1000000:
        s += str(it)
        it += 1
    idx, v = 1, list()
    while idx<=1000000:
        v.append(int(s[idx]))
        idx *= 10
    return reduce(lambda a,b: a*b,v)

if __name__=="__main__":
    start_ = time.time()
    print(' Answer -> %s '.center(width,'-') % ( solution() ))
    print(' %f seconds '.center(width,'-') % ( time.time() - start_))
