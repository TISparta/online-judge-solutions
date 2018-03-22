
# Execution time : 2.032557 seconds

# Solution Explanation
# Compute all the Collatz numbers below 10^6
# And use memoization to avoid unnecessary calculations


import time
width = 40

def solution():
    SIZE = 1000010
    collatz = [0]*SIZE
    _max = [0]*SIZE
    for it in range(1,SIZE):
        ct, num = 1, it
        while num!=1:
            if num<SIZE and collatz[num]:
                ct += collatz[num]-1
                break
            if num&1: num = 3*num+1
            else: num >>= 1
            ct += 1
        collatz[it] = ct
        _max[it] = _max[it-1] if collatz[_max[it-1]]>ct else it
    return _max[1000000]

if __name__=="__main__":
    start_ = time.time()
    print(' Answer -> %s '.center(width,'-') % ( solution() ))
    print(' %f seconds '.center(width,'-') % ( time.time() - start_))
