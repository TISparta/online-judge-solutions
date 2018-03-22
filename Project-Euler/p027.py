
# Execution time : 7.145710 seconds

# Solution Explanation
# A simple brute-force approach with and naive primality test is enough


import time
width = 40

def solution():

    isPrime = lambda p : p > 1 and all((p%it!=0) for it in range(2,int(p**(0.5))+1))

    NP = -1
    for a in range(-999,1000):
        for b in range(-999,1000):
            ct, n = 0, 0
            while True:
                if isPrime(n*n+a*n+b):
                    ct += 1
                else:
                    break
                n += 1
            if ct>NP:
                NP, ans = ct, a*b
    return ans

if __name__=="__main__":
    start_ = time.time()
    print(' Answer -> %s '.center(width,'-') % ( solution() ))
    print(' %f seconds '.center(width,'-') % ( time.time() - start_))
