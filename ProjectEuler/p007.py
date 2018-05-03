
# Execution time : 0.262220 seconds

# Solution Explanation
# 10^4 + 1 < 10^6 / log( 10 ^ 6 ) ( Asymptotic distribution )
# So, if we generate all the numbers below 10^6
# We can get the 10001st prime number


import time
width = 40

def solution():
    SIZE = 1000000
    p = [True]*SIZE
    prime = list()
    for it1 in range(2,SIZE):
        if p[it1]:
            for it2 in range(it1*it1,SIZE,it1):
                p[it2] = False
            prime.append(it1)
    return prime[10000]

if __name__=="__main__":
    start_ = time.time()
    print(' Answer -> %s '.center(width,'-') % ( solution() ))
    print(' %f seconds '.center(width,'-') % ( time.time() - start_))
