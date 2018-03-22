
# Execution time : 0.000561 seconds

# Solution Explanation
# Just implement using the power of Python's built-ins.


import time
width = 40
import datetime

def solution():
    return sum(1 for year in range(1901,2001) for mounth in range(1,13) if datetime.date(year,mounth,1).weekday()==6)

if __name__=="__main__":
    start_ = time.time()
    print(' Answer -> %s '.center(width,'-') % ( solution() ))
    print(' %f seconds '.center(width,'-') % ( time.time() - start_))
