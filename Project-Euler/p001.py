
# Execution time : 0.000050 seconds

# Solution Explanation
# Let a(N,M) = { x : x * M <= N }
# Realize that |a(N,M)| = floor( N/M )
# So if we want to calculate M + 2*M + 3*M + ... <= N
# we have to compute b(N,M) =  M * | a(N,M) | * | a(N,M) + 1 | / 2
# Moreover, for PIE, we have:  | a(N,3) U a(N,5) | = | a(N,3) | + | a(N,5) | - | a(N,3*5) |
# So, the answer is b(N,3) + b(N,5) - b(N,15)


import time
width = 40

def solution():

    b = lambda N, M: M * ( N // M ) * ( N // M + 1 ) // 2

    N = 999
    return b(N,3) + b(N,5) - b(N,15)

if __name__=="__main__":
    start_ = time.time()
    print(' Answer -> %s '.center(width,'-') % ( solution() ))
    print(' %f seconds '.center(width,'-') % ( time.time() - start_))
