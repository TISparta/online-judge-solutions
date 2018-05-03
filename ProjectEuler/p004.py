
# Execution time : 0.357908 seconds

# Solution Explanation
# 3-digit numbers < 10^3
# So a brute-force approach has complexity O(10^6)
# and it is enough


import time
width = 40

def solution():
   return max([it1*it2 for it1 in range(100,1000) for it2 in range(it1,1000) if str(it1*it2)==str(it1*it2)[::-1]])

if __name__=="__main__":
    start_ = time.time()
    print(' Answer -> %s '.center(width,'-') % ( solution() ))
    print(' %f seconds '.center(width,'-') % ( time.time() - start_))
