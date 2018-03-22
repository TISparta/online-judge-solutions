
# Execution time : 0.932338 seconds

# Solution Explanation
# Simple brute-force approach is enough and the limit
# of the iteration can be ealy aproximated givin large values


import time
width = 40

def solution():
    return sum(it1 for it1 in range(10,200000) if sum(int(it2)**5 for it2 in str(it1))==it1)

if __name__=="__main__":
    start_ = time.time()
    print(' Answer -> %s '.center(width,'-') % ( solution() ))
    print(' %f seconds '.center(width,'-') % ( time.time() - start_))
