from collections import deque
for tc in range(int(input())):
    n = int(input())
    d = deque(map(int,input().split()))
    pib = 1<<33
    for _ in range(n):
        if pib<max(d[0],d[-1]):
            break
        else:
            pib = max(d[0],d[-1])
            if pib==d[-1]:
                d.pop()
            else:
                d.popleft()
    print("Yes" if (len(d)==0) else "No")
