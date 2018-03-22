N,M = map(int,input().split())
for i in range(1,N,2): 
   print(3*(N-i)//2*"-"+i*".|."+3*(N-i)//2*"-")
print("WELCOME".center(M,"-"))
for i in range(N-2,-1,-2): 
   print(3*(N-i)//2*"-"+i*".|."+3*(N-i)//2*"-")
