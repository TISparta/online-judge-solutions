#include <bits/stdc++.h>

#define SIZE 110

using namespace std;

bool is_prime[SIZE], ok;
vector <int> prime;
int FFactors[SIZE][SIZE], N, D, v[SIZE];
vector< pair<int, int> > Factors;
long long ans;

void sieve(){
   memset(is_prime, true, sizeof is_prime);
   for(int it1 = 2; it1 < SIZE; it1++)
      if( is_prime[it1] ){
         for(int it2 = it1 * it1; it2 < SIZE; it2 += it1)
            is_prime[it2] = false;
         prime.push_back(it1);
      }
}

void FactorialFactors(){
   for(int num = 2; num  < SIZE; num++){
      int pib = num;
      for(int it = 0; it < prime.size(); it++){
         int ct = 0;
         while( pib % prime[it] == 0 ) pib /= prime[it], ct++;
         FFactors[num][ prime[it] ] = FFactors[num - 1][ prime[it] ] + ct;
      }
   }
}

void GetFactors(int n){
   Factors.clear();
   for(int it = 0; it < prime.size(); it++)
      if( n % prime[it] == 0 ){
         int ct = 0;
         while( n % prime[it] == 0 ) n /= prime[it], ct++;
         Factors.push_back( make_pair(prime[it], ct) );
      }
   if( n != 1 ) ok = false;
}

long long solve(){
   if( ok == false ) return 0;
   ans = 1;
   copy(FFactors[N], FFactors[N] + SIZE, v);
   for(int it = 0; it < Factors.size(); it++)
      v[ Factors[it].first ] -= Factors[it].second;
   for(int it = 2; it < SIZE; it++)
      if( v[it] < 0 ) return 0;
      else ans *= v[it] + 1;
   return ans;
}
int main(){
   sieve();
   FactorialFactors();
   while( scanf("%d %d", &N, &D), N | D){
      ok = true;
      GetFactors(D);
      printf("%lld\n", solve());
   }
   return(0);
}
