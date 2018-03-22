
# Execution time : 0.007948 seconds

# Solution Explanation
# Brute-force approach is enough


import time
width = 40
from functools import reduce

def solution():
    s = open('input_p008.in','r').readline()
    return max([reduce(lambda a,b: int(a)*int(b),s[it:it+13]) for it in range(len(s)-13)])

if __name__=="__main__":
    start_ = time.time()
    print(' Answer -> %s '.center(width,'-') % ( solution() ))
    print(' %f seconds '.center(width,'-') % ( time.time() - start_))
