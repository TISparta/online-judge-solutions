import collections
import math

def solution():
    for tc in range(1, 1 + int(input())):
        s = input()
        ans = math.factorial(len(s))
        for it in collections.Counter(s).values():
            ans //= math.factorial(it)
        print("Data set %d: %d" %(tc, ans))

if __name__=="__main__":
    solution()
