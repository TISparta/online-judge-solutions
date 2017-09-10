def solution():

    def gcd(a, b):
        return a if b==0 else gcd(b, a % b)

    tc = 0
    while True:
        tc += 1
        line = input().strip()
        if line == '-1':
            break
        j, n = line.split()
        j = int(j)
        k = len(n) - 2 - j
        n = n[2:] + ( 20 * n [-j:] if j != 0 else '' )
        if j != 0:
            num = int(n[:k+j]) - ( int(n[:k]) if k != 0 else 0 )
        else:
            num = int(n)
        den = ( 10**(k + j) - 10**k if j != 0 else 10**k)
        print('Case %d: %d/%d' %(tc, num // gcd(num, den), den // gcd(num, den)))

if __name__=="__main__":
    solution()
