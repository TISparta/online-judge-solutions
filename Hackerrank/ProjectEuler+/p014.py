from sys import stdin, stdout

def main():
    SIZE = 5000010
    collatz = [0]*SIZE
    _max = [0]*SIZE
    for it in range(1,SIZE):
        ct, num = 1, it
        while num!=1:
            if num<SIZE and collatz[num]:
                ct += collatz[num]-1
                break
            if num&1: num = 3*num+1
            else: num >>= 1
            ct += 1
        collatz[it] = ct
        _max[it] = _max[it-1] if collatz[_max[it-1]]>ct else it
    for tc in range(int(stdin.readline())):
        stdout.write(str(_max[int(stdin.readline())])+'\n')

if __name__=="__main__":
    main()
