
# Execution time : 0.001408 seconds

# Solution Explanation
# Let v = { v1, v2, ..., vn } be values
# We want to find in how many ways we can sum s with
# element of v if we can get as many items of v as we need
# ( We can choose as many times and element as we want )
# So, we can define the following recurrence
# sol(i,s) = if s<0 -> 0, if i <= n -> sol(i,s-v[i]) + sol(i+1,s), if i==n -> 1 if s=0 else 0
# So the answer is sol(1,200)
# And we note that there are overlapping cases in this recurrence
# So we can implement it using DP


import time
width = 40

def solution():
    v = [1,2,5,10,20,50,100,200]
    memo = [[-1 for i in range(210)] for j in range(10)]

    def ways(idx,s):
        if s<0: return 0
        if idx==8 and s!=0: return 0
        if idx==8 and s==0: return 1
        if memo[idx][s]!=-1: return memo[idx][s]
        memo[idx][s] = ways(idx,s-v[idx])+ways(idx+1,s)
        return memo[idx][s]

    return ways(0,200)

if __name__=="__main__":
    start_ = time.time()
    print(' Answer -> %s '.center(width,'-') % ( solution() ))
    print(' %f seconds '.center(width,'-') % ( time.time() - start_))
