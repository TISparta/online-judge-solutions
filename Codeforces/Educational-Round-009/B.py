# Tags: Implementation
# Difficulty: 1.5
# Priority: 5
# Date: 09-06-2017

n, p = int( input() ) + 1, [0] + list( map( int, input().split() ) )
s = '_' + input()
ans = sum( p[i] for i in range(n) if s[i] == 'B' )
f1 = [0]
for i in range(1, n):
    f1.append(f1[-1] + ( 0 if s[i] == 'A' else p[i] ))
f1 += [0]
f2 = [0]
for i in reversed(range(1, n)):
    f2.append(f2[-1] + ( 0 if s[i] == 'A' else p[i] ) )
f2 += [0]
f2.reverse()
ac = 0
for i in range(1, n):
    if s[i] == 'A': ac += p[i]
    ans = max(ans, ac + f2[i + 1])
ac = 0
for i in reversed( range(1, n) ):
    if s[i] == 'A': ac += p[i]
    ans = max(ans, ac + f1[i - 1])
print(ans)
