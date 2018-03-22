#include <bits/stdc++.h>

using namespace std;

const int LEN = 1000000, SIZE = 1000000;

long long x, n, c[SIZE];
char line[LEN], *p;

long long Horner(long long X){
   long long fX = c[0] * --n;
   for(int it = 1; it < n; it++)
      fX = fX * X + c[it] * ( n - it );
   return fX;
}

int main(){
   while(~scanf("%lld\n", &x)){
      cin.getline(line, LEN);
      p = strtok(line, " ");
      n = 0;
      while(p)
         c[n++] = atoll(p), p = strtok(NULL, " ");
      printf("%lld\n", Horner(x));
   }
   return(0);
}
