from collections import deque
d = deque()
for tc in range(int(input())):
    line = input().split()
    eval("d.%s(%s)" %(line[0],line[1] if len(line)==2 else ""))
print(" ".join(map(str,d)))
