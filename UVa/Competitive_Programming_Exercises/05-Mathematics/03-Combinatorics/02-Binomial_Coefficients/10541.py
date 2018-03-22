def main():
    SIZE = 300
    C = [[0 for i in range(SIZE)] for j in range(SIZE) ]
    for i in range(SIZE):
        C[i][0], C[i][i] = 1, 1
    for i in range(2, SIZE):
        for k in range(1, i):
            C[i][k] = C[i - 1][k] + C[i - 1][k - 1]
    for tc in range( int( input() ) ):
        N, K, *V = map(int, input().split())
        N -= sum(V)
        print(C[N + 1][K])

if __name__ == '__main__':
    main()
