
# Execution time : 0.336308 seconds

# Solution explanation
# 600851475143 is of the orden 10^12
# ans = max{ p : p | N and p is prime }
# But ans < sqrt( 10^12 ) = 10^6
# So a brute-force approach is enough


import time
width = 40

def solution():
    SIZE = 1000010
    p = [True]*SIZE
    primes = list()
    for it1 in range(2,SIZE):
        if p[it1]:
            for it2 in range(2*it1,SIZE,it1):
                p[it2] = False
            primes.append(it1)
    N = 600851475143
    for it in reversed(primes):
        if N%it==0:
            return it

if __name__=="__main__":
    start_ = time.time()
    print(' Answer -> %s '.center(width,'-') % ( solution() ))
    print(' %f seconds '.center(width,'-') % ( time.time() - start_))
