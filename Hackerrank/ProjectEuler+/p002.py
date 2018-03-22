def main():
    fib = [1,2]
    while fib[-1]<4*1e16:
        fib.append(fib[-1]+fib[-2])
    for tc in range(int(input())):
        N = int(input())
        print(sum([it for it in fib if not it&1 and it<=N]))

if __name__=="__main__":
    main()
