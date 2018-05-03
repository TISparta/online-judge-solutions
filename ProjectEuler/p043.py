
# Execution time : 8.871481 seconds

# Solution Explanation
# Generate all the permutations of { 1, 2, ... , 9 }
# And simplily add the ones that verify the conditions


import time
width = 40
from itertools import permutations

def solution():
    prime = [0,2,3,5,7,11,13,17]
    ans = 0
    for v in permutations('0123456789'):
        s = ''.join(v)
        if all(int(s[k:k+3])%prime[k]==0 for k in range(1,8)):
            ans += int(s)
    return ans

if __name__=="__main__":
    start_ = time.time()
    print(' Answer -> %s '.center(width,'-') % ( solution() ))
    print(' %f seconds '.center(width,'-') % ( time.time() - start_))
