input()
s = set(map(int,input().split()))
for it in range(int(input())):
    line = input().split()
    if line[0]=="pop":
        s.pop()
    elif line[0]=="remove":
        s.remove(int(line[1]))
    else:
        s.discard(int(line[1]))
print(sum(s))
