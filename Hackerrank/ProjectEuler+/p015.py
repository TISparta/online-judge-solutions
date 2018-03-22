from math import factorial as f

def comb(a,b):
    return f(a)//(f(b)*f(a-b))

def main():
    for tc in range(int(input())):
        N, M = map(int,input().split())
        print(comb(N+M,M)%1000000007)

if __name__=="__main__":
    main()
