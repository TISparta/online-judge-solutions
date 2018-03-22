def solution():
    for tc in range( int( input() ) ):
        v = list( input().strip().split() )
        word = input()
        ans = ''
        for k in range(26):
            for w in v:
                if len(w) == len(word):
                    ok = True
                    for it in range(len(word)):
                        n1 = ord(w[it]) - ord('a')
                        n2 = ord(word[it]) - ord('a')
                        ok &= ( ( n2 + k ) % 26 == n1 )
                    if ok:
                        ans = ans + chr( ord('a') + k)
                        break
        print(ans)


if __name__ == '__main__':
    solution()
