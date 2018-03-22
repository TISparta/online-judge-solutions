from functools import reduce

def main():
    v = list()
    v.append([0]*23)
    v.append([0]*23)
    v.append([0]*23)
    for it in range(20):
        v.append(list(map(int,input().split())))
        v[it+3].extend([0,0,0])
    v.append([0]*23)
    v.append([0]*23)
    v.append([0]*23)
    ans = 0
    for it1 in range(3,23):
        for it2 in range(20):
            ans = max(ans,reduce(lambda a,b: a*b,[v[it1][it2+k] for k in range(4)]))
            ans = max(ans,reduce(lambda a,b: a*b,[v[it1+k][it2] for k in range(4)]))
            ans = max(ans,reduce(lambda a,b: a*b,[v[it1-k][it2+k] for k in range(4)]))
            ans = max(ans,reduce(lambda a,b: a*b,[v[it1+k][it2+k] for k in range(4)]))
    print(ans)

if __name__=="__main__":
    main()
