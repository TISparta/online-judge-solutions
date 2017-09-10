import sys

def solution():

    not_prime = lambda num : any(num%it==0 for it in range(2,num))

    comp = [it for it in range(4,70) if not_prime(it)]

    ans, LIM = set([1]), 1<<64

    for a in range(2,(1<<16) + 1):
        for b in comp:
            if a**b < LIM:
                ans.add(a**b)
            else:
                break
    for it in sorted(ans):
        sys.stdout.write(str(it) + '\n')

if __name__=="__main__":
    solution()
