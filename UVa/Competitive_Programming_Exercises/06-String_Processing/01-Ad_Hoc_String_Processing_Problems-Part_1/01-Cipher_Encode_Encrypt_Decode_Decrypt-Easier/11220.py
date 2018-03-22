def solution():
    first = True
    for tc in range(1, 1 + int( input() ) ):
        if not first:
            print('')
        else:
            input()
        first = False
        print('Case #%d:' %(tc))
        while True:
            try:
                v = list( input().strip().split() )
                if len(v) == 0:
                    break
                word, ct = '', 0
                for w in v:
                    if ct < len(w):
                        word = word + w[ct]
                        ct += 1
                print(word)

            except EOFError:
                break

if __name__ == '__main__':
    solution()
