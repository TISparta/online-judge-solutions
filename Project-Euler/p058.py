
# Execution time : 19.687730 seconds

# Solution Explanation
# Brute-force approach until found the answer


import time
width = 40
import math

def solution():

    isPrime = lambda n : all(n%it!=0 for it in range(2,int(math.sqrt(n)+1)))

    square, diagonal, num, primes = 1, 1, 1, 0
    while True:
        square += 2
        diagonal += 4
        for it in range(4):
            num += square - 1
            if isPrime(num):
                primes += 1
        if primes / diagonal < 0.10:
            return square

if __name__=="__main__":
    start_ = time.time()
    print(' Answer -> %s '.center(width,'-') % ( solution() ))
    print(' %f seconds '.center(width,'-') % ( time.time() - start_))
