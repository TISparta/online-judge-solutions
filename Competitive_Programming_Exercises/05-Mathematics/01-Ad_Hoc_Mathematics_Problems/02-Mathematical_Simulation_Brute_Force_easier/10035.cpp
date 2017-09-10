#include <bits/stdc++.h>

using namespace std;

int main(){
   long a, b;
   int carry;
   bool foo;
   while(scanf("%ld %ld", &a, &b), a | b){
      carry = 0;
      foo = false;
      while(a | b){
         if((a % 10 + b % 10 + foo) / 10)
            carry++, foo = true;
         else
            foo = false;
         a /= 10;
         b /= 10;
      }
      if(carry){
         if(carry == 1)
            printf("1 carry operation.\n");
         else
            printf("%d carry operations.\n", carry);
      }
      else
         printf("No carry operation.\n");
   }
   return(0);
}
