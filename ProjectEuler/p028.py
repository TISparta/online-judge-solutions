
# Execution time : 0.000568 seconds

# Solution Explanation
# http://oeis.org/search?q=1%2C25%2C101&language=english&go=Search
# Length of the diagonal for the problem is 500
# So a straightforward implementation is enough


import time
width = 40

def solution():
    return 1 + 4 * sum(4 * k**2 + k + 3 - 2 * ( (k+2) % (k+1) ) for k in range(1,501))

if __name__=="__main__":
    start_ = time.time()
    print(' Answer -> %s '.center(width,'-') % ( solution() ))
    print(' %f seconds '.center(width,'-') % ( time.time() - start_))
