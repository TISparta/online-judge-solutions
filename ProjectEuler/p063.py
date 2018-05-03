
# Execution time : 0.000104 seconds

# Solution Explanation
# Consider number of the form a**n
# If a>=10 then a ^ n > n
# So, we just need to check for 1 <= a <= 9


import time
width = 40

def solution():
    ans = 0
    for it in range(1,10):
        n = 1
        while True:
            if len(str(it**n))!=n:
                break
            ans += 1
            n += 1
    return ans

if __name__=="__main__":
    start_ = time.time()
    print(' Answer -> %s '.center(width,'-') % ( solution() ))
    print(' %f seconds '.center(width,'-') % ( time.time() - start_))
