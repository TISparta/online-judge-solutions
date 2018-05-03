
# Execution time : 0.130513 seconds

# Solution Explanation
# Simple brute force is enough
# By problem 44 we know that
# num is a pentagonal number iff 6 | ( 1 + sqrt( 1 + 24 * num ) )
# By similar calculations
# num is a hexagonal number iff 4 | ( 1 + sqrt( 1 + 8 * num ) )
# So brute-force with these considerations is enough


import time
width = 40
import math

def solution():

    isPentagonal = lambda num : ( 1 + math.sqrt( 1 + 24 * num ) ) % 6 == 0

    isHexagonal = lambda num : ( 1 + math.sqrt( 1 + 8 * num ) ) % 4 == 0

    it = 286
    while True:
        num = it * ( it + 1 ) // 2
        if isPentagonal(num) and isHexagonal(num):
            return num
        it += 1

if __name__=="__main__":
    start_ = time.time()
    print(' Answer -> %s '.center(width,'-') % ( solution() ))
    print(' %f seconds '.center(width,'-') % ( time.time() - start_))
