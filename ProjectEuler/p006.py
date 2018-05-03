
# Execution time : 0.000055 seconds

# Solution Explanation
# s1(N) = 1^2 + 2^2 + ... + n^2 = n * ( n + 1 ) / 2
# s2(N) = ( 1 + 2 + ... + n )^2 = ( n * ( n + 1 ) / 2 )^2
# So ans = s2(100) - s1(100)


import time
width = 40

def solution():
    N = 100
    return (N * (N + 1) // 2)**2 - N * (N + 1) * (2 * N + 1) // 6

if __name__=="__main__":
    start_ = time.time()
    print(' Answer -> %s '.center(width,'-') % ( solution() ))
    print(' %f seconds '.center(width,'-') % ( time.time() - start_))
