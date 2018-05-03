def main():
    for tc in range(int(input())):
        N = int(input())
        print((N*(N+1)//2)**2-N*(N+1)*(2*N+1)//6)

if __name__=="__main__":
    main()
