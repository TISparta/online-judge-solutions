from sys import stdin,stdout

def main():
   while True:
      v = list(map(int, stdin.readline().rstrip().split()))
      if len(v) == 0:
         break
      ans = v[0]
      for i in range(len(v) - 1):
         ans = max(ans, v[i])
         p = v[i]
         for j in range(i + 1, len(v) - 1):
            p *= v[j]
            ans = max(ans, p)
      stdout.write(str(int(ans)) + "\n")

if __name__ == "__main__":
   main()
