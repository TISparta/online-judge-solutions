s1 = input()
s2 = input()
ans = 0
for i in range(len(s1)-len(s2)+1):
   if s2 == s1[i:len(s2)+i]:
      ans += 1
print(ans)
