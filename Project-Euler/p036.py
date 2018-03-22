
# Execution time : 0.768209 seconds

# Solution Explanation
# And naive brute-force approach is enough.


import time
width = 40

def solution():
    return sum(it for it in range(1000000) if str(it)[:]==str(it)[::-1] and bin(it)[2:]==bin(it)[:1:-1])

if __name__=="__main__":
    start_ = time.time()
    print(' Answer -> %s '.center(width,'-') % ( solution() ))
    print(' %f seconds '.center(width,'-') % ( time.time() - start_))
