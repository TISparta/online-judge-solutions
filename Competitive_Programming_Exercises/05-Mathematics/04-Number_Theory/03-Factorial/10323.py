import math

def solution():
    while True:
        try:
            n = int(input())
            if 0 <= n < 8 or ( n < 0 and n % 2 == 0 ):
                print('Underflow!')
            elif n > 13 or ( n < 0 and n % 2 != 0 ):
                print('Overflow!')
            else:
                print(math.factorial(n))
        except EOFError:
            break

if __name__=="__main__":
    solution()
