def main():
    SIZE = 10000
    p = [True]*SIZE
    prime = list()
    for it1 in range(2,SIZE):
        if p[it1]:
            for it2 in range(2*it1,SIZE,it1):
                p[it2] = False
            prime.append(it1)
    nd = list()
    num, pib = 1, 1
    while True:
        d = 1
        for it in prime:
            if num==1 or it>num: break
            if num%it==0:
                ct = 1
                while num%it==0:
                    num //= it
                    ct += 1
                d *= ct
        if num!=1: d *= 2
        nd.append((d,pib*(pib+1)//2))
        if nd[-1][0]>1000: break
        pib += 1
        num = pib*(pib+1)//2
    for tc in range(int(input())):
        N = int(input())
        for a, b in nd:
            if a>N:
                print(b)
                break

if __name__=="__main__":
    main()
