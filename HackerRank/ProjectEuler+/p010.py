def main():
    SIZE = 1000010
    p = [True]*SIZE
    for it1 in range(2,SIZE):
        if p[it1]:
            for it2 in range(2*it1,SIZE,it1):
                p[it2] = False
    s = [0]*SIZE
    for it in range(2,SIZE):
        s[it] = s[it-1]
        if p[it]:
            s[it] += it
    for tc in range(int(input())):
        print(s[int(input())])

if __name__=="__main__":
    main()
