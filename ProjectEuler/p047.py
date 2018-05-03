
# Execution time : 0.683267 seconds

# Solution Explanation
# We can make a table of length 'SIZE' initialized in zeros
# Then we can iterate from 2 to SIZE and check
# if table[it] = 0 then it is prime, so the numbers
# 2 * it, 3 * it , 4 * it ,... have this prime in its prime
# descomposition, so we add 1 prime factor to that numbers
# In this way, in the end of the iteration we have the number
# of distinct prime factors of each number less than 'SIZE'
# Finally, we just need to check if we find the desirable
# numbers that verify the conditions, if not, we just increase
# the value of 'SIZE' until find the answer


import time
width = 40

def solution():
    SIZE = 1000000
    table = [0] * SIZE
    for it1 in range(2,SIZE):
        if table[it1]==0:
            for it2 in range(it1+it1,SIZE,it1):
                table[it2] += 1
    for num in range(SIZE-4):
        if all(table[it]==4 for it in range(num,num+4)):
            return num


if __name__=="__main__":
    start_ = time.time()
    print(' Answer -> %s '.center(width,'-') % ( solution() ))
    print(' %f seconds '.center(width,'-') % ( time.time() - start_))
