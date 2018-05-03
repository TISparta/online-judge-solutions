
# Execution time : 0.258888 seconds

# Solution Explanation
# We can iterate from 1, 2, 3 , ...
# from each number, we can associate a
# triangule number, f(x) = x * ( x + 1 ) / 2
# We can get the prime factorization of f(x)
# from which we can get the number of divisor
# So if the number of divisor of f(x) is
# greater than 500 we are done, else we continue

import time
width = 40

def solution():
    SIZE = 1000
    p = [True]*SIZE
    prime = list()
    for it1 in range(2,SIZE):
        if p[it1]:
            for it2 in range(it1*it1,SIZE,it1):
                p[it2] = False
            prime.append(it1)
    nd = list()
    num, pib = 1, 1
    while True:
        d = 1
        for it in prime:
            if num==1 or it>num: break
            if num%it==0:
                ct = 1
                while num%it==0:
                    num //= it
                    ct += 1
                d *= ct
        if num!=1: d *= 2
        nd.append((d,pib*(pib+1)//2))
        if nd[-1][0]>500: break
        pib += 1
        num = pib*(pib+1)//2
    return nd[-1][1]

if __name__=="__main__":
    start_ = time.time()
    print(' Answer -> %s '.center(width,'-') % ( solution() ))
    print(' %f seconds '.center(width,'-') % ( time.time() - start_))
