#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

const long long L1 = 3e5, L2 = 9e10;

int tc;
ull N, d;
bool is_prime[L1], first;
vector <ull> prime;

void sieve(){
   memset(is_prime, true, sizeof is_prime);
   is_prime[0] = is_prime[1] = false;
   for(ull i = 2; i < L1; i++)
      if( is_prime[i] ){
         for(ull j = i * i; j < L1; j += i)
            is_prime[j] = false;
         prime.push_back(i);
      }
}

ull mulMod(ull a, ull b, ull c){
   ull ret = 0, pib = a % c;
   while(b){
      if( b & 1 ) ret += pib;
      pib <<= 1;
      if( ret >= c ) ret -= c;
      if( pib >= c ) pib -= c;
      b >>= 1;
   }
   return ret;
}

ull powMod(ull a, ull b, ull c){
   ull ret = 1, pib = a;
   while(b){
      if( b & 1 ) ret = mulMod(ret, pib, c);
      pib = mulMod(pib, pib, c);
      b >>= 1;
   }
   return ret;
}

bool MillerRobin(ull num, int it = 10){
   if( num < 2 ) return false;
   if( num < 4 ) return true;
   if( not ( num & 1 ) ) return false;
   ull s = num - 1;
   while( not ( s & 1 ) ) s >>= 1;
   while(it--){
      ull rd = rand() % ( num - 1 ) + 1, pib = s; 
      ull ret = powMod(rd, pib, num);
      if( ret == -1 or ret == 1 ) continue;
      while( pib != num - 1 and ret != 1 and ret != num - 1 ){
         ret = mulMod(ret, ret, num);
         pib <<= 1;
      }
      if( ret != num - 1 ) return false;
   }
   return true;
}

ull gcd(ull a, ull b){
   return b == 0 ? a : gcd(b, a % b);
}

ull PollardRho(ull num){
   int i = 0, k = 2;
   ull ret = 3, pib = 3, d;
   while(++i){
      ret = ( mulMod(ret, ret, num) + num - 1 ) % num;
      if( pib - ret >= 0 ) d = gcd(pib - ret, num);
      else d = gcd(pib - ret, num);
      if( d != 1 and d != num ) return d;
      if( i == k ) pib = ret, k <<= 1;
   }
}

void GetFactors(){
   for(int i = 0; i < prime.size() and prime[i] * prime[i] <= N and N != 1; i++)
      if( N % prime[i] == 0 ){
         int e = 0;
         while( N % prime[i] == 0 ) N /= prime[i], e++;
         if( e == 1 ) printf( first ? " %lld" : " * %lld", prime[i]);
         else printf( first ? " %llu^%d" : " * %lld^%d", prime[i], e);
         first = false;
      }
}

int main(){
   sieve();
   scanf("%d", &tc);
   while(tc--){
      first = true;
      scanf("%lld", &N);
      printf("%lld =", N);
      if( N < L1 ){
         if( is_prime[N] ) printf(" %lld", N);
         else{
            GetFactors();
            if( N != 1 ) printf( first ? " %lld" : " * %lld", N);
         }
      }
      else if( N < L2 ){
         GetFactors();
         if( N != 1 ) printf( first ? " %lld" : " * %lld", N);
      }
      else{
         if( MillerRobin(N) ) printf(" %lld", N);
         else{
            GetFactors();
            if( N != 1 ){
               if( MillerRobin(N) ) printf(first ? " %lld" : " * %lld", N);
               else{
                  ull d = PollardRho(N);
                  if( d > N / d ) d = N / d;
                  if( d != N / d ) printf( first ? " %lld * %lld" : " * %lld * %lld", d, N / d);
                  else printf(first ? " %lld^2" : " * %lld^2", d);
               }
            }
         }
      }
      putchar('\n');
   }
   return(0);
}
