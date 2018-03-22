n = int(input())
v = []
for it in range(n):
   a = input()
   b = float(input())
   v.append([a,b])
v.sort()
value = sorted(set([b for a,b in v]))[1]
for a,b in v:
   if b==value:
      print(a)
