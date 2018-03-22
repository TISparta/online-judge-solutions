s = input()
n = int(input())
for it in range(0,len(s),n):
   print("".join(sorted(set(s[it:it+n]),key=s[it:it+n].index)))
