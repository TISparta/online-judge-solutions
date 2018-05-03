def main():
    for tc in range(int(input())):
        N = int(input())
        N -= 1
        print(3*(N//3)*(N//3+1)//2+5*(N//5)*(N//5+1)//2-15*(N//15)*(N//15+1)//2)

if __name__=="__main__":
    main()
