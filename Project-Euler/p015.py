
# Execution time : 0.000060 seconds

# Solution Explanation
# We are in the point (0,0) and we want to move to the point (n,m)
# As we can just go right or down, so we are going to need n + m steps
# n steps down and m steps right
# Now if we represent a path with a string of 1 and 0
# 1 for down and 0 for right, as the len of the string is fixed
# if we have complete the string with n ones, the other must be zeros and viceversa
# So, the number of distint such paths is C(n+m,n) = C(n+m,m)
# For this problem n = m = 20, so the answer is C(40,20)

import time
width = 40
from math import factorial as f

def solution():

    comb = lambda a,b: f(a)//(f(b)*f(a-b))

    return comb(40,20)

if __name__=="__main__":
    start_ = time.time()
    print(' Answer -> %s '.center(width,'-') % ( solution() ))
    print(' %f seconds '.center(width,'-') % ( time.time() - start_))
