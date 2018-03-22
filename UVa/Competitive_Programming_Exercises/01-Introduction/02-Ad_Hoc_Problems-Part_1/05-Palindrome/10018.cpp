#include <bits/stdc++.h>

using namespace std;

int tc, ct;
unsigned num;

unsigned reversed_number(unsigned  n){
   unsigned pib = 0;
   while(n) pib = pib * 10 + n % 10, n /= 10;
   return pib;
}

void Lychrel_number(){
   ct = 0;
   while( ct < 50 ){
      ct++;
      num += reversed_number(num);
      if( num == reversed_number(num) ) break;
   }
}

int main(){
   scanf("%d", &tc);
   while( tc-- ){
      scanf("%u", &num);
      Lychrel_number();
      printf("%d %u\n", ct, num);
   }
   return(0);
}
