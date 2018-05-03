def main():
    SIZE = 1000000
    p = [True]*SIZE
    prime = list()
    for it1 in range(2,SIZE):
        if p[it1]:
            for it2 in range(2*it1,SIZE,it1):
                p[it2] = False
            prime.append(it1)
    for tc in range(int(input())):
        print(prime[int(input())-1])

if __name__=="__main__":
    main()
