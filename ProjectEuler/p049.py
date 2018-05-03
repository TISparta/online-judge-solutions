
# Execution time : 0.440223 seconds

# Solution Explanation
# We can simplily iterate through all the 4-digits numbers
# Then generate all the permutation of this number and check
# if the desirable sequence, distinct from the given one, is found


import time
width = 40
import itertools
import math

def solution():

    isPrime = lambda p: p>=1000 and all(p%it!=0 for it in range(2,int(math.sqrt(p))+1))

    for num in range(1488,10000):
        v = [int(''.join(ch for ch in it)) for it in itertools.permutations(str(num))]
        v.sort()
        for it1 in range(len(v)):
            for it2 in range(it1+1,len(v)):
                r = v[it2] - v[it1]
                if r > 0 and v[it1]!=1487 and v[it2]+r in v:
                    if isPrime(v[it1]) and isPrime(v[it2]) and isPrime(v[it2]+r):
                        return str(v[it1])+str(v[it2])+str(v[it2]+r)


if __name__=="__main__":
    start_ = time.time()
    print(' Answer -> %s '.center(width,'-') % ( solution() ))
    print(' %f seconds '.center(width,'-') % ( time.time() - start_))
