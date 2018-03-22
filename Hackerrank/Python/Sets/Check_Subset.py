for tc in range(int(input())):
    n,s1,m,s2 = input(), set(input().split()), input(), set(input().split())
    print(s1.issubset(s2))
