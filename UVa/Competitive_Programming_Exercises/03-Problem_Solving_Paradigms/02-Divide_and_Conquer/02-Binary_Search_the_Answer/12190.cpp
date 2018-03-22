#include <bits/stdc++.h>

using namespace std;

long long A, B, lo, hi, mid, bee;

long long price(long long num){
   long long aux;
   aux = num <= 100 ?  num * 2 : 200;
   if(num > 100){
      if(num <= 10000) aux += (num - 100) * 3;
      else aux += 29700;
   }
   if(num > 10000){
      if(num <= 1000000) aux += (num - 10000) * 5;
      else aux += 4950000; 
   }
   if(num > 1000000) aux += (num - 1000000) * 7;
   return aux;
}

long long invPrice(long long num){
   long long aux;
   aux = num <= 200 ? num / 2 : 100;
   if(num > 200){
      if(num <= 29900) aux += (num - 200) / 3;
      else aux += 9900;
   }
   if(num > 29900){
      if(num <= 4979900) aux += (num - 29900) / 5;
      else aux += 990000;
   }
   if(num > 4979900) aux += (num - 4979900) / 7;
   return aux;
}

int main(){
   while(scanf("%lld %lld", &A, &B), A | B){
      bee = invPrice(A);
      lo = 0, hi = bee;
      while(lo != hi){
         mid = (lo + hi) >> 1;
         if(price(bee - mid) - price(mid) > B) lo = mid + 1;
         else hi = mid;
      }
      printf("%lld\n", price(lo));
   }
   return(0);
}
