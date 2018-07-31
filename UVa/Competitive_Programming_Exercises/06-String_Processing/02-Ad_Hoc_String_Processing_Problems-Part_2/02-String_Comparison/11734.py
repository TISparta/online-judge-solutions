def solution():
    for tc in range( 1, 1 + int( input() ) ):
        print('Case %d: ' %(tc), end = '')
        a, b = input(), input()
        if a == b:
            print('Yes')
        elif a.replace(' ', '') == b.replace(' ', ''):
            print('Output Format Error')
        else:
            print('Wrong Answer')

if __name__ == '__main__':
    solution()
