from sys import stdin,stdout

def main():
   rt = [1]
   for it in range(1,310):
      rt.append(rt[it-1]*(it<<1)*((it<<1)-1)//(it+1))
   while True:
      idx = int(stdin.readline())
      if idx==0:
         break
      stdout.write(str(rt[idx])+"\n")

if __name__ == "__main__":
   main()
