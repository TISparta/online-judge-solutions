def main():

    def f(n):
        return sum(k ** k for k in range(1, n + 1)) % 10

    def CycleFinding():
        lambda_ = 1
        while any(f(i) != f(i + lambda_) for i in range(1, lambda_ + 1)):
            lambda_ += 1
        return lambda_

    MOD = CycleFinding()
    while True:
        N = int(input())
        if N == 0:
            break
        print(f(N % MOD))

if __name__=='__main__':
    main()
