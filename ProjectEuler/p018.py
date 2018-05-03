
# Execution time : 0.028454 seconds

# Solution Explanation
# If we are in position (i,j) we can just go to (i+1,j) or (i+1,j+1)
# The input is really small, so we can use the naive recurrent solution
# sol(i,j) = v[i][j] + max{ sol(i+1,j) , sol(i+1,j+1) } is i <= fixex_number else 0
# So, the answer is sol(1,1)
# We can use backtracking to implement the above recurrence


import time
width = 40

def solution():

    def backtrack(i,j,s):
        if i==15: return s
        return max(backtrack(i+1,j,s+v[i][j]),backtrack(i+1,j+1,s+v[i][j]))

    v = [list(map(int,line.split())) for line in open('input_p018.in','r')]
    return backtrack(0,0,0)

if __name__=="__main__":
    start_ = time.time()
    print(' Answer -> %s '.center(width,'-') % ( solution() ))
    print(' %f seconds '.center(width,'-') % ( time.time() - start_))
