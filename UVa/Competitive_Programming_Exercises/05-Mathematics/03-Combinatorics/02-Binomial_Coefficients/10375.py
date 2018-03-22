def main():
    SIZE = 10010
    F = [1]
    for i in range(1, SIZE):
        F += [ i * F[-1] ]
    while True:
        try:
            p, q, r, s = map(int, input().split())
            print("{0:.5f}".format(F[p] * F[s] * F[r - s] / ( F[q] * F[p - q] * F[r] )))
        except EOFError:
            break

if __name__ == '__main__':
    main()
