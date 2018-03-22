
# Execution time : 4.526085 seconds

# Solution Explanation
# Brute-force approach is enough.


import time
width = 40

def solution():
    SIZE = 1000000
    p = [True]*SIZE
    prime, circularPrime = list(), 0
    for it1 in range(2,SIZE):
        if p[it1]:
            for it2 in range(it1*it1,SIZE,it1):
                p[it2] = False
        prime.append(str(it1))
    for it in prime:
        s, ok = it, True
        for k in range(len(s)):
            s = s[1:]+s[0]
            if p[int(s)]==False:
                ok = False
        if ok:
            circularPrime += 1
    return circularPrime

if __name__=="__main__":
    start_ = time.time()
    print(' Answer -> %s '.center(width,'-') % ( solution() ))
    print(' %f seconds '.center(width,'-') % ( time.time() - start_))
