
# Execution time : 4.636978 seconds

# Solution Explanation
# Just implement the brute-force idea.


import time
width = 40

def solution():

    def isTruncablePrime(num):
        return all([p[int(num[k:])] and p[int(num[:k+1])] for k in range(len(num))])

    SIZE = 1000000
    p = [True]*SIZE
    p[0] = p[1] = False
    for it1 in range(2,int(SIZE**0.5)+1):
        if p[it1]:
            for it2 in range(it1*it1,SIZE,it1):
                p[it2] = False
    return sum(it for it in range(11,SIZE) if isTruncablePrime(str(it)))

if __name__=="__main__":
    start_ = time.time()
    print(' Answer -> %s '.center(width,'-') % ( solution() ))
    print(' %f seconds '.center(width,'-') % ( time.time() - start_))
