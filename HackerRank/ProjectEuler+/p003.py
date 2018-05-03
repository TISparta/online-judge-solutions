def main():
    SIZE = 1000010
    p = [True]*SIZE
    primes = list()
    for it1 in range(2,SIZE):
        if p[it1]:
            for it2 in range(2*it1,SIZE,it1):
                p[it2] = False
            primes.append(it1)
    for tc in range(int(input())):
        N = int(input())
        ans = 0
        for it in primes:
            if N%it==0:
                ans = max(ans,it)
                while N%it==0: N //= it
        print(ans if N==1 else N)

if __name__=="__main__":
    main()
