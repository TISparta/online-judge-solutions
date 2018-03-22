
# Execution time : 0.010646 seconds

# Solution Explanation
# A naive brute-force apprach is enough.


import time
width = 40

def solution():
    x, y = 1, 1
    for num in range(10,100):
        for den in range(num+1,100):
            ch = list(set(str(num))&set(str(den)))
            if len(ch)==1 and ch[0]!='0':
                a, b = str(num), str(den)
                a = int(a[:a.find(ch[0])]+a[a.find(ch[0])+1:])
                b = int(b[:b.find(ch[0])]+b[b.find(ch[0])+1:])
                if num*b==den*a:
                    x, y = x*a, y*b
    def gcd(a,b):
        return a if b==0 else gcd(b,a%b)

    return y // gcd(x,y)

if __name__=="__main__":
    start_ = time.time()
    print(' Answer -> %s '.center(width,'-') % ( solution() ))
    print(' %f seconds '.center(width,'-') % ( time.time() - start_))
