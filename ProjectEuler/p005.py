
# Execution time : 0.000115 seconds

# Solution Explanation
# ans = min{ n : d | n ( d = 1, 2, ... , 20 ) }
# So ans = lcm( 1, 2, 3, ... , 20 )

import time
width = 40
from functools import reduce

def solution():
    v = [it for it in range(1,21)]
    for it1 in range(len(v)):
        for it2 in range(it1+1,len(v)):
            if v[it2] % v[it1]==0:
                v[it2] //= v[it1]
    return reduce(lambda a,b: a*b,v)

if __name__=="__main__":
    start_ = time.time()
    print(' Answer -> %s '.center(width,'-') % ( solution() ))
    print(' %f seconds '.center(width,'-') % ( time.time() - start_))
