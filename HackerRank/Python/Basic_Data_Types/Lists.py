v = []
tc = int(input())
for t in range(tc):
   s = input().split()
   if(s[0]=="insert"):
      v.insert(int(s[1]),int(s[2]))
   elif(s[0]=="print"):
      print(v)
   elif(s[0]=="remove"):
      v.remove(int(s[1]))
   elif(s[0]=="append"):
      v.append(int(s[1]))
   elif(s[0]=="sort"):
      v.sort()
   elif(s[0]=="pop"):
      v.pop()
   elif(s[0]=="reverse"):
      v.reverse()
