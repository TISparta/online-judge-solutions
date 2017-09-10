#include<bits/stdc++.h>

using namespace std;

long long a, b, x, y, num, den, foo;
double n, pib, prec;
bool ok;

int main(){
   while(scanf("%lld %lld %lf", &a, &b, &n) == 3){
      pib = (double)a / b;
      ok = true;
      for(long long y = 1; ok; y++){
         x = pib * y - 2;
         while(x * b <= a * y)
            x++;
         prec = (double)x / y - pib;
         if(prec - n < 1e-15){
            printf("%lld %lld\n", x, y);
               ok = false;
               break;
            }
      }
   }
   return(0);
}
