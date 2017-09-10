def solution():

    SIZE = 1010
    factorial, ac = [1], 1
    for it in range(1,SIZE):
        ac *= it
        factorial.append(ac)

    while True:
        try:
            n = int(input())
            print("%d!\n%d" %(n, factorial[n]))
        except EOFError:
            break

if __name__=="__main__":
    solution()
