
# Execution time : 1.550719 seconds

# Solution Explanation
# Suppose num is a pentagonal number, so there exists a natural number n
# such that n * ( 3 * n - 1 ) / 2 = num
# So 3 * n^2 - n - 2 * num = 0
# Then  n = 1 + sqrt( 1 + 24 * num ) / 6
# So num is a pentagonal number iff 6 | ( 1 + sqrt( 1 + 24 * num ) )
# Thanks to this, we can generate and fixed number of pentagonal numbers
# And check if we find the answer by a brute-force approach
# If we get it, we are done, else we generate more pentagonal numbers


import time
width = 40
import math

def solution():

    def isPentagonal(num):
        return ((1 + math.sqrt(1 + (24 * num) )) % 6 == 0)

    pentagonals = [ n * ( 3*n - 1) // 2 for n in range(1,3000)]
    for i in range(len(pentagonals)):
        for j in reversed(range(i)):
            if isPentagonal(pentagonals[i] + pentagonals[j]) and isPentagonal(pentagonals[i]-pentagonals[j]):
                return pentagonals[i]-pentagonals[j]

if __name__=="__main__":
    start_ = time.time()
    print(' Answer -> %s '.center(width,'-') % ( solution() ))
    print(' %f seconds '.center(width,'-') % ( time.time() - start_))
