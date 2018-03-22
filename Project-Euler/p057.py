
# Execution time : 0.003174 seconds

# Solution Explanation
# e(0) -> 1
# e(1) -> 1 + 1 / ( 1 + e(0) )
# e(2) -> 1 + 1 / ( 1 + e(1) )
# ...
# e(n) -> 1 + 1 / ( 1 + e(n-1) )
# So, let e(n-1) = num / den, then
# e(n) -> ( num + 2 * den ) / ( num + den )


import time
width = 40

def solution():
    num, den, ans = 1, 1, 0
    for it in range(1000):
        num, den = num + 2 * den, num + den
        if len(str(num)) > len(str(den)):
            ans += 1
    return ans

if __name__=="__main__":
    start_ = time.time()
    print(' Answer -> %s '.center(width,'-') % ( solution() ))
    print(' %f seconds '.center(width,'-') % ( time.time() - start_))
