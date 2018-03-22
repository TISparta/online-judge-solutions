
# Execution time : 0.860832 seconds

# Solution Explanation
# Brute-force approach is enough


import time
width = 40

def solution():
    SIZE = 2000010
    p = [True]*SIZE
    for it1 in range(2,SIZE):
        if p[it1]:
            for it2 in range(it1*it1,SIZE,it1):
                p[it2] = False
    s = [0]*SIZE
    for it in range(2,SIZE):
        s[it] = s[it-1]
        if p[it]:
            s[it] += it
    return s[2000000]

if __name__=="__main__":
    start_ = time.time()
    print(' Answer -> %s '.center(width,'-') % ( solution() ))
    print(' %f seconds '.center(width,'-') % ( time.time() - start_))
