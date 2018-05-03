
# Execution time : 35.874564 seconds

# Solution Explanation
# The idea is to use backtrack technique
# The recurrence is
# Let v be initially an empty set and idx an index number
# Then, backtrack(idx,v) = backtrack(idx+i,v U prime[idx+i])
# for idx<i<=length(primes generated)
# if the set { v U prime[idx+1] } satisfy the conditions of the problem
# So, we can implement this using a list to represent the vector, just for convenience
# But, the implementation using nested loops is faster the the recursive one
# So, I implemented in the iterative way just for decreasing the execution time


import time
width = 40

def solution():
    SIZE = 10000
    sieve = [True] * SIZE
    p = list()
    for it1 in range(2,SIZE):
        if sieve[it1]:
            for it2 in range(it1*it1,SIZE,it1):
                sieve[it2] = False
            p.append(it1)

    def check(num):
        if num<SIZE:
            return sieve[num]
        for it in p:
            if num%it==0:
                return False
        return True

    def isPrime(s1,s2):
        return check(int(s1+s2)) and check(int(s2+s1))

    for it1 in range(len(p)):
        for it2 in range(it1,len(p)):
            v = [ str(p[it1]), str(p[it2]) ]
            if isPrime(v[0], v[1]):
                for it3 in range(it2+1,len(p)):
                    v.append( str(p[it3]) )
                    if isPrime(v[0], v[2]) and isPrime(v[1], v[2]):
                        for it4 in range(it3+1,len(p)):
                            v.append( str(p[it4]) )
                            if isPrime(v[0], v[3]) and isPrime(v[1], v[3]) and isPrime(v[2], v[3]):
                                for it5 in range(it4+1,len(p)):
                                    v.append( str(p[it5]) )
                                    if isPrime(v[0], v[4]) and isPrime(v[1], v[4]) and isPrime(v[2], v[4]) and isPrime(v[3], v[4]):
                                        return sum(int(it) for it in v)
                                    v.pop()
                            v.pop()
                    v.pop()

if __name__=="__main__":
    start_ = time.time()
    print(' Answer -> %s '.center(width,'-') % ( solution() ))
    print(' %f seconds '.center(width,'-') % ( time.time() - start_))
