#include <bits/stdc++.h>

#define SIZE 1000010

using namespace std;

int numFactors[SIZE], N;

void sieve(){
   for(int it1 = 2; it1 < SIZE; it1++)
      if( numFactors[it1] == 0 )
         for(int it2 = it1; it2 < SIZE; it2 += it1)
            numFactors[it2]++;
}

int main(){
   sieve();
   while(scanf("%d", &N), N)
      printf("%d : %d\n", N, numFactors[N]);
   return(0);
}
