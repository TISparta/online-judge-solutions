def main():
    SIZE = 1010
    C = [[0 for i in range(SIZE)] for j in range(SIZE) ]
    for i in range(SIZE):
        C[i][0], C[i][i] = 1, 1
    for i in range(2, SIZE):
        for k in range(1, i):
            C[i][k] = C[i - 1][k] + C[i - 1][k - 1]
    for tc in range(1, 1 + int( input() )):
        n = ( int( input() ) - 2 ) // 2
        print('Case %d: %d' %(tc, C[2 * n + 1][n + 1]))

if __name__ == '__main__':
    main()
