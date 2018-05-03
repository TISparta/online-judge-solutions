
# Execution time : 0.206389 seconds

# Solution Explanation
# Brute-force approach is enough.


import time
width = 40

def solution():
    v = [0]*1010
    for a in range(1,1000):
        for b in range(a,1000-a):
            c = int((a*a+b*b)**0.5)
            if a*a+b*b==c*c and a+b+c<=1000:
                v[a+b+c] += 1
    return v.index(max(v))

if __name__=="__main__":
    start_ = time.time()
    print(' Answer -> %s '.center(width,'-') % ( solution() ))
    print(' %f seconds '.center(width,'-') % ( time.time() - start_))
