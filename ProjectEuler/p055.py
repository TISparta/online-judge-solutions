
# Execution time : 0.064418 seconds

# Solution Explanation
# Brute-force approach is enough.


import time
width = 40

def solution():

    def isLychrel(num):
        ct = 0
        while ct<50:
            ct += 1
            num = num + int(str(num)[::-1])
            if str(num)==str(num)[::-1]:
                return False
        return True

    return sum(1 for it in range(1,10000) if isLychrel(it))

if __name__=="__main__":
    start_ = time.time()
    print(' Answer -> %s '.center(width,'-') % ( solution() ))
    print(' %f seconds '.center(width,'-') % ( time.time() - start_))
