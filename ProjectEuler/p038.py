# Execution time : 0.048212 seconds

# Solution Explanation
# Brute-force approach is enough.


import time
width = 40

def solution():
    v = list()
    for n in range(2,10):
        num = 1
        while True:
            s = ''.join(str(num*it) for it in range(1,n+1))
            if len(s)>9:
                break
            if ''.join(sorted(s))=='123456789':
                v.append(s)
            num += 1
    return max(v)

if __name__=="__main__":
    start_ = time.time()
    print(' Answer -> %s '.center(width,'-') % ( solution() ))
    print(' %f seconds '.center(width,'-') % ( time.time() - start_))
