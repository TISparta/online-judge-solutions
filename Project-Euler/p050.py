
# Execution time : 0.636313 seconds

# Solution Explanation
# Simple brute-force approach is enough


import time
width = 40

def solution():
    SIZE = 1000000
    sieve = [True] * SIZE
    primes = list()
    for it1 in range(2,SIZE):
        if sieve[it1]:
            for it2 in range(it1*it1,SIZE,it1):
                sieve[it2] = False
            primes.append(it1)
    ms = -1
    for it1 in range(len(primes)):
        ct, num = 1, primes[it1]
        for it2 in range(it1+1,len(primes)):
            if num + primes[it2] >= SIZE:
                break
            num += primes[it2]
            ct += 1
            if sieve[num] and ct>ms:
                ms, ans = ct, num
    return ans


if __name__=="__main__":
    start_ = time.time()
    print(' Answer -> %s '.center(width,'-') % ( solution() ))
    print(' %f seconds '.center(width,'-') % ( time.time() - start_))
