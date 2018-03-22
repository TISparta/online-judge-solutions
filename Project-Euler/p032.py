
# Execution time : 15.249712 seconds

# Solution Explanation
# A simple brute-force approach is enough


import time
width = 40
from itertools import permutations as p

def solution():
    u = set()
    for v in p('123456789'):
        v = ''.join(it for it in v)
        for i in range(1,9):
            for j in range(i+1,9):
                num1, num2, num3 = int(v[:i]), int(v[i:j]), int(v[j:])
                if num1*num2==num3:
                    u.add(num3)
    return sum(u)


if __name__=="__main__":
    start_ = time.time()
    print(' Answer -> %s '.center(width,'-') % ( solution() ))
    print(' %f seconds '.center(width,'-') % ( time.time() - start_))
