def main():
    while True:
        m, n = map(int, input().split())
        if m == n == 0:
            break
        print(pow(m, n, 10))

if __name__=="__main__":
    main()
