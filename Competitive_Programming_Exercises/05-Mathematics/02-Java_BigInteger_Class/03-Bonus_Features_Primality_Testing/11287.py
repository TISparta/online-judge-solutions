def solution():

    isPrime = lambda n: p > 1 and all(n % i != 0 for i in range(2, int(n ** 0.5 + 1)))

    while True:
        p, a = map(int, input().split())
        if p == 0 and a == 0:
            break
        print('yes' if pow(a, p, p) == a and not isPrime(p) else 'no')

if __name__ == '__main__':
    solution()
