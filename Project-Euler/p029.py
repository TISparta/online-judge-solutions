
# Execution time : 0.009511 seconds

# Solution Explanation
# Using the power of Python's built-ins is enough


import time
width = 40

def solution():
    return len(set([a**b for a in range(2,101) for b in range(2,101)]))

if __name__=="__main__":
    start_ = time.time()
    print(' Answer -> %s '.center(width,'-') % ( solution() ))
    print(' %f seconds '.center(width,'-') % ( time.time() - start_))
