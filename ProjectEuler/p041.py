
# Execution time : 0.280123 seconds

# Solution Explanation
# Brute-force solution with naive primality test is enough.


import time
width = 40
from itertools import permutations

def solution():

    isPrime = lambda p: all(p%it!=0 for it in range(2,int(p**0.5)+1))

    return ''.join(max(v for v in permutations('1234567') if isPrime(int(''.join(v)))))

if __name__=="__main__":
    start_ = time.time()
    print(' Answer -> %s '.center(width,'-') % ( solution() ))
    print(' %f seconds '.center(width,'-') % ( time.time() - start_))
