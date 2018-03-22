from sys import stdin,stdout

def main():
   catalan = [1]
   for it in range(1,1005):
      catalan.append(catalan[it-1]*((it<<2)-2)//(it+1))
   while True:
      idx = stdin.readline()
      if len(idx)==0:
         break
      stdout.write(str(catalan[int(idx)])+"\n")

if __name__ == "__main__":
   main()
