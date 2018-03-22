#include <bits/stdc++.h>

using namespace std;

const int LEN = 200, SIZE = 100;

int n, m, c[SIZE], x[SIZE];
char line[LEN], *p;

int Horner(int X){
   int fX = c[0];
   for(int i = 1; i < n; i++)
      fX = fX * X + c[i];
   return fX;
}

int main(){
   while(cin.getline(line, LEN)){
      p = strtok(line, " ");
      n = 0;
      while(p)
         c[n++] = atoi(p), p = strtok(NULL, " ");
      cin.getline(line, LEN);
      p = strtok(line, " ");
      m = 0;
      while(p)
         x[m++] = atoi(p), p = strtok(NULL, " ");
      for(int it = 0; it < m; it++)
         printf( it != m - 1 ? "%d " : "%d\n", Horner(x[it]));
   }
   return(0);
}
