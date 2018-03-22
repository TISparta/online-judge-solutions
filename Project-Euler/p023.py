
# Execution time : 6.094368 seconds

# Solution Explanation
# Let A = sum{n : n cannot be expressed as the sum of 2 abundant numbers}
# But, the problem states that n must be less than 28123
# So, we can express A as the sum of all the number below of 28123 less
# the numbers that can be expressed as the sum of the abundant numbers


import time
width = 40

def solution():
    SIZE = 28124
    sd = [0] * SIZE
    for it1 in range(1,SIZE):
        for it2 in range(it1+it1,SIZE,it1):
            sd[it2] += it1
    v = [n for n in range(1,SIZE) if sd[n]>n]
    return 28123 * 28124 // 2 - sum(set(v[it1]+v[it2] for it1 in range(len(v)) for it2 in range(it1,len(v)) if v[it1]+v[it2] <= 28123))

if __name__=="__main__":
    start_ = time.time()
    print(' Answer -> %s '.center(width,'-') % ( solution() ))
    print(' %f seconds '.center(width,'-') % ( time.time() - start_))
