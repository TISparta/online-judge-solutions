#include <bits/stdc++.h>

using namespace std;

int tc, HH, MM;

bool is_palindrome(int n){
   int pib = 0, tmp = n;
   while(tmp) pib = pib * 10 + tmp % 10, tmp /= 10;
   return ( n == pib );
}

int main(){
   scanf("%d", &tc);
   while(tc--){
      scanf("%2d:%2d",&HH, &MM);
      while(true){
         MM++;
         if(MM == 60) MM = 0, HH++;
         if(HH == 24) HH = 0;
         if(is_palindrome(HH * 100 + MM))
            break;
      }
      printf("%.2d:%.2d\n", HH, MM);
   }
   return(0);
}
