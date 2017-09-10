import sys

def solution():
    while True:
        N = int(sys.stdin.readline())
        if N == -1 :
            break
        if N == 0 or N == 1:
            sys.stdout.write(str(10 + N) + '\n')
            continue
        ans = ''
        for it in reversed(range(2,10)):
            while N % it == 0 :
                ans += str( it )
                N //= it
        if N != 1 :
            sys.stdout.write('There is no such number.\n')
        else :
            if len( ans ) == 1 :
                ans += '1'
            sys.stdout.write(ans[::-1] + '\n')

if __name__=="__main__":
    solution()
