from functools import reduce

def main():
    for tc in range(int(input())):
        N, K = map(int,input().split())
        s = input()
        print(max([reduce(lambda a,b: int(a)*int(b),s[it:it+K]) for it in range(len(s)-K)]))

if __name__=="__main__":
    main()
