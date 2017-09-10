#include <bits/stdc++.h>

using namespace std;

int n, px, py, pib;
long long num, d;

int main(){
   while(scanf("%d %lld", &n, &num), n | num){
         d = ( sqrt(num) + 1) / 2;
         px = py = ( n + 1 ) / 2 + d;
         if( (2 * d - 1) * (2 * d - 1) == num ) px -= 1, py -= 1;
         else{
            pib = (2 * d + 1) * (2 * d + 1);
            d *= 2;
            if(num >= pib - d) px -= pib - num;
            else if(num >= pib - 2 * d) py -= pib - d - num, px -= d;
            else if(num >= pib - 3 * d) py -= d, px -= d, px += pib - 2 * d - num;
            else py -= d, py += pib - 3 * d - num;
         }
         printf("Line = %d, column = %d.\n", px, py);   
   }
   return(0);
}
