
# Execution time : 0.004891 seconds

# Solution Explanation
# Let v represent the given square matrix
# Then, sol(i,j) = v[i][j] + min{sol[i-1][j], sol[i][j-1]}
# If both terms inside min make sense, else we just take
# the one that have sense
# So, the answer is sol(n,n), where n = Number of rows of v


import time
width = 40

def solution():
    v = [list(map(int,line.split(','))) for line in open('input_p081.in','r')]
    for col in range(1,len(v)):
        v[0][col] += v[0][col-1]
    for row in range(1,len(v)):
        v[row][0] += v[row-1][0]
    for row in range(1,len(v)):
        for col in range(1,len(v)):
            v[row][col] += min(v[row-1][col],v[row][col-1])
    return v[-1][-1]

if __name__=="__main__":
    start_ = time.time()
    print(' Answer -> %s '.center(width,'-') % ( solution() ))
    print(' %f seconds '.center(width,'-') % ( time.time() - start_))
