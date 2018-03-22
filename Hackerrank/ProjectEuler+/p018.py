def main():
    def backtrack(i,j,s):
        if i==N: return s
        return max(backtrack(i+1,j,s+v[i][j]),backtrack(i+1,j+1,s+v[i][j]))

    for tc in range(int(input())):
        v = list()
        N = int(input())
        for row in range(N):
            v.append(list(map(int,input().split())))
        print(backtrack(0,0,0))

if __name__=="__main__":
    main()
