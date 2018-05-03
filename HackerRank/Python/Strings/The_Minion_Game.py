s = input()
Stuart = Kevin = 0
v = ['A','E','I','O','U']
for it in range(len(s)):
   if any(s[it] == vowel for vowel in v):
      Kevin += len(s)-it
   else:
      Stuart += len(s)-it
if Stuart > Kevin:
   print("Stuart %d" %Stuart)
elif Kevin > Stuart:
   print("Kevin %d" %Kevin)
else:
   print("Draw")
