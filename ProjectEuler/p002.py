
# Execution time : 0.000069 seconds

# Solution Explanation
# Just generate all the required Fibonacci numbers
# and sum the even-valued terms.


import time
width = 40

def solution():
    fib = [1,2]
    while fib[-1]<4*1e6:
        fib.append(fib[-1]+fib[-2])
    return sum([it for it in fib if not it&1])

if __name__=="__main__":
    start_ = time.time()
    print( ' Answer -> %s '.center(width,'-') % ( solution() ))
    print( ' %f seconds '.center(width,'-') % (time.time() - start_) )
