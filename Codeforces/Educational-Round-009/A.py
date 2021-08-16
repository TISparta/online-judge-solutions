# Tags: Implementation
# Difficulty: 1.0
# Priority: 5
# Date: 09-06-2017

n, p = map(int, input().split())
a = [input() for _ in range(n)]
ans, power = 0, 0
for s in reversed(a):
    power <<= 1
    if s[-1] == 's': power += 1
    ans += power * p // 2
print(ans)
