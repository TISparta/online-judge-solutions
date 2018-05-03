
# Execution time : 0.026728 seconds

# Solution Explanation
# 1 / n = 0.a
# a = 1 mod n * 10 / n then 1 / n = 0.ab
# b = 1 mod n * 10 mod n * 10 / n then 1 / n = 0.abc
# c = 1 mod n * 10 mod n * 10 mod n * 10 / n then | / n = 0.abcd
# .... until n = 0.abc..x and x = a or b or c or ...
# Because, in this case, we are going to repeat the cicle
# So, the algorith is as follow:
# let v = { 0, 0, ..., 0 } and |v| = n
# First x = 1, pos = 0
# v[x] = pos and x = x * 10 mod n and pos = pos + 1
# if v[x] != 0 we are done, we have found a cycle of length pos - v[x]
# else we continue the process

import time
width = 40

def solution():
    v = [0]*1000
    for it in range(2,1000):
        x, pos = 1, 0
        vis = [0]*it
        while vis[x]==0:
            vis[x] = pos
            x = (x*10)%it
            pos += 1
        v[it] = pos-vis[x]
    return v.index(max(v))

if __name__=="__main__":
    start_ = time.time()
    print(' Answer -> %s '.center(width,'-') % ( solution() ))
    print(' %f seconds '.center(width,'-') % ( time.time() - start_))
