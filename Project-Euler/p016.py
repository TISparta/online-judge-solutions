
# Execution time : 0.000167 seconds

# Solution Explanation
# Just implement it using the power of Python's built-ins


import time
width = 40

def solution():
    return sum([int(it) for it in str(1<<1000)])

if __name__=="__main__":
    start_ = time.time()
    print(' Answer -> %s '.center(width,'-') % ( solution() ))
    print(' %f seconds '.center(width,'-') % ( time.time() - start_))
