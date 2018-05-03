
# Execution time : 0.251594 seconds

# Solution Explanation
# Brute-force approach is enough.


import time
width = 40

def solution():
    return max(sum(int(it) for it in str(a**b)) for a in range(100) for b in range(100))

if __name__=="__main__":
    start_ = time.time()
    print(' Answer -> %s '.center(width,'-') % ( solution() ))
    print(' %f seconds '.center(width,'-') % ( time.time() - start_))
