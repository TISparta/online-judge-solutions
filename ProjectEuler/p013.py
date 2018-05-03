
# Execution time : 0.000208 seconds

# Solution Explanation
# Just sum the number and returns the ten last digits


import time
width = 40

def solution():
    return str(sum([int(line) for line in open('input_p013.in','r')]))[:10]

if __name__=="__main__":
    start_ = time.time()
    print(' Answer -> %s '.center(width,'-') % ( solution() ))
    print(' %f seconds '.center(width,'-') % ( time.time() - start_))
