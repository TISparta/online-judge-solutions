def main():
    for tc in range(int(input())):
        N, ans = int(input()), -1
        for a in range(1,N//2):
            b = (N*(2*a-N))//(2*(a-N))
            c = N-a-b
            if a+b+c==N and a*a+b*b==c*c:
                ans = max(ans,a*b*c)
        print(ans)

if __name__=="__main__":
    main()
