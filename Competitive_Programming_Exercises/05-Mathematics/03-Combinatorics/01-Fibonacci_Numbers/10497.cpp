#include <bits/stdc++.h>

#define LIM 800
#define DIGITS 1978

using namespace std;

int seq[LIM + 1][DIGITS], n, z, carry, m, k, pib, ind;

void print_seq(int p){
   if(p == 1){
      printf("0\n");
      return;
   }
   for(int i = 0; i < DIGITS; i++)
      if(seq[p][i] != 0){
         z = i;
         break;
      }
   for(int i = z; i < DIGITS; i++)
      printf("%d", seq[p][i]);
   putchar('\n');
   return;
}

void sum_one(int p){
   for(int r = DIGITS - 1; r > 0; r--){
      seq[p][r] += 1;
      if(seq[p][r] < 10){
         break;
      }
      seq[p][r] %= 10;
   }
}

void subt_one(int p){
   for(int r= DIGITS - 1; r > 0; r--){
      seq[p][r] -= 1;
      if(seq[p][r] < 0)
         seq[p][r] += 10;
      else{
         break;
      }
   }
   return;
}

void mult(int p){
   m = p;
   pib = 0;
   while(m){
      carry = 0;
      k = m % 10;
      ind = DIGITS - 1 - pib;
      for(int r = DIGITS - 1; r > 0; r--){
         seq[p][ind] += seq[p - 1][r] * k + carry;
         carry = seq[p][ind] / 10;
         seq[p][ind] %= 10;
         ind--;
      }
      m /= 10;
      pib++;
   }
   return;
}

void generateSeq(){
   seq[0][DIGITS - 1] = 1;
   for(int i = 1; i <= LIM; i++){
      mult(i);
      if(i & 1)
         subt_one(i);
      else
         sum_one(i);
   }
   return;
}

int main(){
   generateSeq();
   while(scanf("%d", &n), n != -1)
      print_seq(n);
   return(0);
}
