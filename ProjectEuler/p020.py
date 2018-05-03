
# Execution time : 0.000121 seconds

# Solution explanation
# Just implement using the power of Python's built-ins.


import time
width = 40
from math import factorial as f

def solution():
    return sum((int(it) for it in str(f(100))))

if __name__=="__main__":
    start_ = time.time()
    print(' Answer -> %s '.center(width,'-') % ( solution() ))
    print(' %f seconds '.center(width,'-') % ( time.time() - start_))
