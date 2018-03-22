
# Execution time : 0.004307 seconds

# Solution Explanation
# Generate 100 triangule numbers
# And just check for eeach word if
# the corresponding sum is any of the
# triangle numbers formed


import time
width = 40

def solution():
    v = list(map(lambda s: s[1:-1],open('input_p042.in','r').readline().split(',')))
    triangle = set(n*(n+1)//2 for n in range(1,100))
    return sum(1 for name in v if sum(ord(ch)-ord('A')+1 for ch in name) in triangle)

if __name__=="__main__":
    start_ = time.time()
    print(' Answer -> %s '.center(width,'-') % ( solution() ))
    print(' %f seconds '.center(width,'-') % ( time.time() - start_))
