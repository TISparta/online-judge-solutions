
# Execution time : 0.004195 seconds

# Solution Explanation
# Let v represent the given square matrix
# Then, sol(i,j) = v[i][j] + max{sol[i+1][j], sol[i+1][j+1]}
# If both terms inside min make sense
# So, the answer is sol(1,1)


import time
width = 40

def solution():
    v = [list(map(int,line.split())) for line in open('input_p067.in','r')]
    for row in reversed(range(len(v)-1)):
        for col in range(len(v[row])):
            v[row][col] += max(v[row+1][col],v[row+1][col+1])
    return v[0][0]

if __name__=="__main__":
    start_ = time.time()
    print(' Answer -> %s '.center(width,'-') % ( solution() ))
    print(' %f seconds '.center(width,'-') % ( time.time() - start_))
