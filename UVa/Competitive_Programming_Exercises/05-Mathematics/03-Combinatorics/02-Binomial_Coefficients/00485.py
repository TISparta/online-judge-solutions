def main():
    SIZE = 210
    C = [[0 for i in range(SIZE)] for j in range(SIZE) ]
    for i in range(SIZE):
        C[i][0], C[i][i] = 1, 1
    for i in range(2, SIZE):
        for k in range(1, i):
            C[i][k] = C[i - 1][k] + C[i - 1][k - 1]
    ok = False
    for i in range(SIZE):
        if ok:
            break
        print(' '.join( str(C[i][j]) for j in range(i + 1)))
        mx = max(C[i][j] for j in range(i + 1))
        if mx >= 1e60:
            ok = True

if __name__ == '__main__':
    main()
