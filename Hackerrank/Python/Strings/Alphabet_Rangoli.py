import string
from textwrap import wrap
abc = string.ascii_lowercase
n = int(input())
width = 4*n-3
for i in range(n-2,-1,-1):
   print(("-".join(wrap(abc[n-1:i:-1]+abc[i+2:n],1))).center(width,"-"))
print("-".join(wrap(abc[n-1::-1]+abc[1:n],1)))
for i in range(1,n):
   print(("-".join(wrap(abc[n-1:i:-1]+abc[i:n],1))).center(width,"-"))
