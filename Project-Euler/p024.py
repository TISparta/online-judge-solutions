
# Execution time : 0.827900 seconds

# Solution Explanation
# Using the power of Python's built-ins is  enough

import time
width = 40
from itertools import permutations as p

def solution():
    return ''.join(str(s) for s in list(p([it for it in range(10)]))[999999])

if __name__=="__main__":
    start_ = time.time()
    print(' Answer -> %s '.center(width,'-') % ( solution() ))
    print(' %f seconds '.center(width,'-') % ( time.time() - start_))
