from functools import reduce

def main():
    for tc in range(int(input())):
        v = [it for it in range(1,int(input())+1)]
        for it1 in range(len(v)):
            for it2 in range(it1+1,len(v)):
                if v[it2]%v[it1]==0:
                    v[it2] //= v[it1]
        print(reduce(lambda a,b: a*b,v))

if __name__=="__main__":
    main()
