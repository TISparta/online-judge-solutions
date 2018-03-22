#include <bits/stdc++.h>

using namespace std;

const int SIZE = 55, LEN = 100;

int tc, d, n, pos1, pos2, z1, z2;
long long C[SIZE][SIZE];
char line[LEN], x[LEN], y[LEN];

void BinomialCoef(){
   for(int i = 0; i < SIZE; i++) C[i][0] = C[i][i] = 1;
   for(int i = 2; i < SIZE; i++)
      for(int k = 1; k < i; k++)
         C[i][k] = C[i - 1][k] + C[i - 1][k - 1];
}

void read(){
   cin.getline(line, LEN);
   for(int i = 0; line[i]; i++)
      if( line[i] == '+' ) pos1 = i;
      else if( line[i] == '^' ) pos2 = i;
   d = n = 0;
   for(int i = 1; i < pos1; i++) x[d++] = line[i];
   x[d] = '\0', d = 0;
   for(int i = pos1 + 1; i + 1 < pos2; i++) y[d++] = line[i];
   y[d] = '\0';
   for(int i = pos2 + 1; line[i]; i++) n = 10 * n + ( line[i] - '0' );
}

void print(int t){
   printf("Case %d: ", t);
   printf("%s", x);
   if( n != 1 ) printf("^%d", n);
   for(int k = 1; k < n; k++){
      z1 = n - k, z2 = k;
      printf("+%lld*%s", C[n][k], x);
      if( z1 != 1 ) printf("^%d", z1);
      printf("*%s", y);
      if( z2 != 1 ) printf("^%d", z2);
   }
   printf("+%s", y);
   if( n != 1 ) printf("^%d", n);
   putchar('\n');
}

int main(){
   BinomialCoef();
   scanf("%d\n", &tc);
   for(int t = 1; t <= tc; t++){
      read();
      print(t);
   }
   return(0);
}
