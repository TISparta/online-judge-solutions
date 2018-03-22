#include <bits/stdc++.h>

using namespace std;

#define DIGIT 105

int fib[501][DIGIT + 1], ct, l1, l2;
char aux1[DIGIT + 1], aux2[DIGIT+1], a[DIGIT + 1], b[DIGIT + 1];
bool ok;

bool cmp_fib(int x){
   ok = true;
   for(int i = 0; i <= DIGIT; i++)
      if(a[i] - '0' > fib[x][i])
         break;
      else if(a[i] - '0' < fib[x][i]){
         ok = false;
         break;
      }
   if(!ok)
      return false;
   for(int i = 0; i <= DIGIT; i++)
      if(b[i] - '0' < fib[x][i])
         break;
      else if(b[i] - '0' > fib[x][i]){
         ok = false;
         break;
      }
   return ok;
}

int main(){
   fib[0][DIGIT] = fib[1][DIGIT] = 1;
   for(int i = 2; i <= 500; i++){
      for(int j = DIGIT; j > 0; j--){
         fib[i][j] += fib[i - 1][j] + fib[i - 2][j];
         if(fib[i][j] > 9)
            fib[i][j - 1] += 1, fib[i][j] %= 10;
      }
   }
   while(true){
      scanf("%s %s", aux1, aux2);
      ct = 0;
      memset(a, '0', sizeof a);
      memset(b, '0', sizeof b);
      l1 = strlen(aux1), l2 = strlen(aux2);
      if(l1 == 1 && l2 == 1 && aux1[0] == '0' && aux2[0] == '0')
         break;
      l1--, l2--;
      for(int i = DIGIT; l1 >= 0; i--, l1--)
         b[i] = aux1[l1];
      for(int i = DIGIT; l2 >= 0; i--, l2--)
         a[i] = aux2[l2];
      for(int i = 1; i <= 500; i++)
         if(cmp_fib(i))
            ct++;
      printf("%d\n", ct);
   }
   return(0);
}
