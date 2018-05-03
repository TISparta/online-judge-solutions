
# Execution time : 0.011573 seconds

# Solution Explanation
# Using the power of Python's built-ins is more than enough.


import time
width = 40

def solution():
    return str(sum(map(lambda n: n**n,range(1,1001))))[-10:]

if __name__=="__main__":
    start_ = time.time()
    print(' Answer -> %s '.center(width,'-') % ( solution() ))
    print(' %f seconds '.center(width,'-') % ( time.time() - start_))
