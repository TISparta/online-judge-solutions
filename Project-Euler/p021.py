
# Execution time : 0.857258 seconds

# Solution Explanation
# Simple brute-force approach is enough


import time
width = 40

def solution():
    SIZE = 10001
    p, prime = [True]*SIZE, list()
    for it1 in range(2,SIZE):
        if p[it1]:
            for it2 in range(it1*it1,SIZE,it1):
                p[it2] = False
            prime.append(it1)
    SD = [0]*SIZE
    for it in range(1,SIZE):
        num, sd = it, 1
        for _p in prime:
            if num%_p==0:
                x, y = _p, _p
                while num%_p==0:
                    num //= _p
                    x *= _p
                sd *= (x-1)//(y-1)
        SD[it] = sd-it
    return sum([it for it in range(1,SIZE) if SD[it]<SIZE and it==SD[SD[it]] and SD[it]!=it])

if __name__=="__main__":
    start_ = time.time()
    print(' Answer -> %s '.center(width,'-') % ( solution() ))
    print(' %f seconds '.center(width,'-') % ( time.time() - start_))
