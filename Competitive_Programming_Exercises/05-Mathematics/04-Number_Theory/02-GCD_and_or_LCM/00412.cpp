#include <bits/stdc++.h>

#define SIZE 60

using namespace std;

int N, v[SIZE], num, den;

int gcd(int a, int b){
   return b == 0 ? a : gcd(b, a % b);
}

int main(){
   while(scanf("%d", &N), N){
      for(int it = 0; it < N; it++) scanf("%d", &v[it]);
      den = num = 0;
      for(int it1 = 0; it1 < N; it1++)
         for(int it2 = it1 + 1; it2 < N; it2++){
            den++;
            if(gcd(v[it1], v[it2]) == 1) num++;
         }
      if(num==0) puts("No estimate for this data set.");
      else printf("%.6f\n", sqrt( 6 * den * 1.0 / num));
   }
   return(0);  
}
