def solution():
    SIZE = 10010
    factorial, ac = [1], 1
    for it in range(1, SIZE):
        ac *= it
        while( ac % 10 == 0 ):
            ac //= 10
        factorial.append(ac)
    while True:
        try:
            n = int(input())
            print('%5d -> %d' %(n, factorial[n] % 10))
        except EOFError:
            break

if __name__=="__main__":
    solution()
