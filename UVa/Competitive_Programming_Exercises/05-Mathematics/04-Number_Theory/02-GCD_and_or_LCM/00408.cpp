#include<bits/stdc++.h>

using namespace std;

int STEP, MOD;

int gcd(int a, int b){
   return b == 0 ? a : gcd(b, a % b);
}

int main(){
   while(scanf("%d %d", &STEP, &MOD)==2){
      if(gcd(STEP, MOD)==1)
         printf("%10d%10d    Good Choice\n\n", STEP, MOD);
      else
         printf("%10d%10d    Bad Choice\n\n", STEP, MOD);
   }
   return(0);
}
