
# Execution time : 0.274199 seconds

# Solution Explanation
# A brute-force approach is enough, so the problem is how to get
# the limit of the iteration, so a naive limit is 10^7
# because factorial(9)*8 is of the order 10^7
# So any number of 8 digits or more will not follow the conditions
# With this limit we can get the answer, but we notice that
# the maximum number that follow the conditions is less than 10^5
# So we can set 10^5 as the new limit

import time
width = 40
from math import factorial as f

def solution():
    s = 0
    for num in range(10,100000):
        if sum(f(int(it)) for it in str(num))==num:
            s += num
    print(s)

if __name__=="__main__":
    start_ = time.time()
    print(' Answer -> %s '.center(width,'-') % ( solution() ))
    print(' %f seconds '.center(width,'-') % ( time.time() - start_))
