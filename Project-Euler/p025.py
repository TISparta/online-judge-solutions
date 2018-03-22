
# Execution time : 0.035527 seconds

# Solution Explanation
# Just generate the Fibonacci numbers until you
# generate a number that contains 1000 digits


import time
width = 40

def solution():
    fib = [1,1]
    while len(str(fib[-1]))<1000:
        fib.append(fib[-1]+fib[-2])
    return len(fib)

if __name__=="__main__":
    start_ = time.time()
    print(' Answer -> %s '.center(width,'-') % ( solution() ))
    print(' %f seconds '.center(width,'-') % ( time.time() - start_))
