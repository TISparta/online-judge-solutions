
# Execution time : 0.002806 seconds

# Solution Explanation
# Using this recurrence -> C(n,k) = C(n-1,k) + C(n-1,k-1)
# And the fact that C(n,0) = C(n,n) = 1
# We can arranged  all the C(n,k) for 1 <= n <= 100 in a table
# And check what values are greater than one-million


import time
width = 40

def solution():
    table = [[0 for it1 in range(110)] for it2 in range(110)]
    for row in range(101): table[row][0] = table[row][row] = 1
    for row in range(1,101):
        for col in range(1,row):
            table[row][col] = table[row-1][col-1] + table[row-1][col]
    return sum(1 for row in range(101) for col in range(row) if table[row][col]>1000000)


if __name__=="__main__":
    start_ = time.time()
    print(' Answer -> %s '.center(width,'-') % ( solution() ))
    print(' %f seconds '.center(width,'-') % ( time.time() - start_))
