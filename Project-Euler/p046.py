
# Execution time : 0.539952 seconds

# Solution Explanation
# Brute-force approach is enough
# But the problem is to find the limit of the iteration
# So, we can use simplily define a variable SIZE
# and increase the value of SIZE until we found the answer
# Note : 10000 was enough


import time
width = 40
import math

def solution():
    SIZE = 10000
    sieve = [True] * SIZE
    sieve[0] = sieve[1] = False
    primes = list()
    for it1 in range(2,SIZE):
        if sieve[it1]:
            for it2 in range(it1*it1,SIZE,it1):
                sieve[it2] = False
            primes.append(it1)
    for num in range(9,SIZE,2):
        if sieve[num] == False:
            ok = False
            for prime in primes:
                if prime > num:
                    break
                if (num - prime) % 2 == 0 and math.sqrt( ( num - prime ) // 2 ) % 1 == 0:
                    ok = True
            if ok == False:
                return num


if __name__=="__main__":
    start_ = time.time()
    print(' Answer -> %s '.center(width,'-') % ( solution() ))
    print(' %f seconds '.center(width,'-') % ( time.time() - start_))
