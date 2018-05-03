n = int(input())
d = dict()
for i in range(n):
   s = input().split()
   d[s[0]] = (float(s[1])+float(s[2])+float(s[3]))/3.0
query = input()
print("%.2f" %d[query])
