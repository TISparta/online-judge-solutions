def solution():

    SIZE = 1010
    factorial, ac = [1], 1
    for it in range(1, SIZE):
        ac *= it
        factorial.append(ac)

    while True:
        try:
            n = int(input())
            print(sum( int(it) for it in str(factorial[n])))
        except EOFError:
            break

if __name__=="__main__":
    solution()
