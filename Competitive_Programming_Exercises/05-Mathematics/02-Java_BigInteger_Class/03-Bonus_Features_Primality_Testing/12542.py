def solution():

    isPrime = lambda n: 1 < n < 100000 and all(n % i != 0 for i in range(2, int(n ** 0.5 + 1)))

    while True:
        s = input()
        if int(s) == 0:
            break
        print(max([int(s[i: i + k]) for i in range(len(s)) for k in range(1, 6) if i + k <= len(s) and isPrime(int(s[i: i + k]))]))

if __name__ == '__main__':
    solution()
