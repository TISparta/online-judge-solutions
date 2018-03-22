#include <bits/stdc++.h>

using namespace std;

int main(){
   int n, sum;
   printf("PERFECTION OUTPUT\n");
   while(scanf("%d",&n), n){
      printf("%5d  ", n);
      sum = 0;
      for(int i = 1; i <= n / 2; i++)
         if(!(n % i))
            sum += i;
      if(sum == n)
         printf("PERFECT\n");
      else if(sum > n)
         printf("ABUNDANT\n");
      else
         printf("DEFICIENT\n");
   }
   printf("END OF OUTPUT\n");
   return(0);
}
