#include <bits/stdc++.h>

#define SIZE 110

using namespace std;

int N, Factors[SIZE][SIZE];
bool is_prime[SIZE];
vector<int> prime;

void sieve(){
   memset(is_prime, true, sizeof is_prime);
   for(int it1 = 2; it1 < SIZE; it1++)
      if(is_prime[it1]){
         for(int it2 = it1 * it1; it2 < SIZE; it2 += it1)
            is_prime[it2] = false;
         prime.push_back(it1);
      }
}

int main(){
   sieve();
   for(int num = 2; num < SIZE; num++){
      int pib = num;
      for(int it = 0; it < prime.size(); it++){
         int ct = 0;
         while( pib % prime[it] == 0) pib /= prime[it], ct++;
         Factors[num][it] = Factors[num - 1][it] + ct;
      }
   }
   while(scanf("%d", &N), N){
      printf("%3d! =", N);
      int ct = 0;
      for(int it = 0; it < SIZE and Factors[N][it]; it++){
         ct++;
         if( ct == 16 ) ct = 1, printf("      ");
         printf(ct != 15 ? "%3d" : "%3d\n", Factors[N][it]);
      }
      if( ct != 15 ) puts("");
   }
   return(0);
}
