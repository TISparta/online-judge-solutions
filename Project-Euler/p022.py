
# Execution time : 0.017250 seconds

# Solution Explanation
# Just use the power of Python's built-ins.


import time
width = 40

def solution():
    v = list(map(lambda s: s[1:-1],open('input_p022.in','r').readline().split(',')))
    return sum((idx+1)*sum(ord(ch)-ord('A')+1 for ch in name) for idx, name in enumerate(sorted(v)))

if __name__=="__main__":
    start_ = time.time()
    print(' Answer -> %s '.center(width,'-') % ( solution() ))
    print(' %f seconds '.center(width,'-') % ( time.time() - start_))
