
# Execution time : 0.523089 seconds

# Solution Explanation
# Brute-force approach is enough.


import time
width = 40

def solution():
    num = 1
    while True:
        if all(sorted(str(num))==sorted(str(num * it)) for it in range(2,7)):
            return num
        num += 1

if __name__=="__main__":
    start_ = time.time()
    print(' Answer -> %s '.center(width,'-') % ( solution() ))
    print(' %f seconds '.center(width,'-') % ( time.time() - start_))
