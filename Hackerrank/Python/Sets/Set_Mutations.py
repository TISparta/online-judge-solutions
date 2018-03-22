input()
s1 = set(map(int,input().split()))
for it in range(int(input())):
    eval("s1.{0}({1})".format(input().split()[0],set(map(int,input().split()))))
print(sum(s1))
