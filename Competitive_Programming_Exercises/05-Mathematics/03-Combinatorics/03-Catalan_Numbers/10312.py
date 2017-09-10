from sys import stdin,stdout

def main():
   catalan = [1]
   for it in range(1,30):
      catalan.append(catalan[it-1]*((it<<2)-2)//(it+1))
   superCatalan = [1,1]
   for it in range(2,30):
      superCatalan.append(((6*it-3)*superCatalan[it-1]-(it-2)*superCatalan[it-2])//(it+1))
   while True:
      idx = stdin.readline()
      if len(idx)==0:
         break
      stdout.write(str(superCatalan[int(idx)-1]-catalan[int(idx)-1])+"\n")

if __name__ == "__main__":
   main()
