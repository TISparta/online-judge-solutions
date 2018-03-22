import math
import collections

def solution():
    while True:
        n = int(input())
        if n==0:
            break
        v = collections.Counter(str(math.factorial(n)))
        print('%d! --' %(n))
        for it in range(5):
            print('   (%d)%5d' %(it, v[str(it)]), end = '')
        print('')
        for it in range(5,10):
            print('   (%d)%5d' %(it, v[str(it)]), end = '')
        print('')

if __name__=="__main__":
    solution()
