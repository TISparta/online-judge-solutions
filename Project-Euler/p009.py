
# Execution time : 0.000421 seconds

# Solution Explanation
# a^2 + b^2 = c^2   ... ( 1 )
# a + b + c = N     ... ( 2 )
# if we let 'a' be a fixed number
# replace c with N - b -a in ( 1 )
# So, we get a^2 + b^2 = ( N - a - b )^2
# So, b = N * ( 2 * a - N) / ( 2 * ( a - N ) )
# and c = N - a - b
# Now, we can iterate for a in range(N/2)
# compute b and c and find the required answer


import time
width = 40

def solution():
    N, ans = 1000, -1
    for a in range(1,N//2):
        b = (N*(2*a-N))//(2*(a-N))
        c = N-a-b
        if a+b+c==N and a*a+b*b==c*c:
            ans = max(ans,a*b*c)
    return ans

if __name__=="__main__":
    start_ = time.time()
    print(' Answer -> %s '.center(width,'-') % ( solution() ))
    print(' %f seconds '.center(width,'-') % ( time.time() - start_))
