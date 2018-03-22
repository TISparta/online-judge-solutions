
# Execution time : 0.003847 seconds

# Solution Explanation
# A simple brute-froce approach is enough


import time
width = 40
from functools import reduce

def solution():
    v = list()
    v.append([0]*23)
    v.append([0]*23)
    v.append([0]*23)
    for line in open('input_p011.in','r'):
        v.append(list(map(int,line.split())))
        v[-1].extend([0,0,0])
    v.append([0]*23)
    v.append([0]*23)
    v.append([0]*23)
    ans = 0
    for it1 in range(3,23):
        for it2 in range(20):
            ans = max(ans,reduce(lambda a,b: a*b,[v[it1][it2+k] for k in range(4)]))
            ans = max(ans,reduce(lambda a,b: a*b,[v[it1+k][it2] for k in range(4)]))
            ans = max(ans,reduce(lambda a,b: a*b,[v[it1-k][it2+k] for k in range(4)]))
            ans = max(ans,reduce(lambda a,b: a*b,[v[it1+k][it2+k] for k in range(4)]))
    return ans

if __name__=="__main__":
    start_ = time.time()
    print(' Answer -> %s '.center(width,'-') % ( solution() ))
    print(' %f seconds '.center(width,'-') % ( time.time() - start_))
