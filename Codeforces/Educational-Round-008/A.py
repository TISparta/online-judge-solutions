# Tags: Implementation
# Difficulty: 1.3 
# Priority: 3
# Date: 08-06-2017

n, b, p = map(int, input().split())
ans1, ans2 = 0, n * p
while n != 1:
    power = 1
    while power * 2 <= n: power *= 2
    ans1 += ( 2 * b + 1 ) * ( power // 2 )
    n = power // 2 + n - power
print(ans1, ans2)
