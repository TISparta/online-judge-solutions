/**
 * > Author : TISparta
 * > Date : 22-03-18
 * > Tags : Number theory, Miller-Robin algorithm, Rho algorithm
 * > Difficulty : 5 / 10
 */

#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

const int L1 = 3e6;
const long long L2 = 9e12;

int tc;
ll n;
bool is_prime[L1], first;
vector <ll> prime;

void sieve(){
   memset(is_prime, true, sizeof is_prime);
   is_prime[0] = is_prime[1] = false;
   for(ll i = 2; i < L1; i++)
      if( is_prime[i] ){
         for(ll j = i * i; j < L1; j += i)
            is_prime[j] = false;
         prime.push_back(i);
      }
}

ll mulMod(ll a, ll b, ll c){
   ll ret = 0, pib = a % c;
   while(b > 0){
      if( b & 1 ) ret += pib;
      pib <<= 1;
      if( ret >= c ) ret -= c;
      if( pib >= c ) pib -= c;
      b >>= 1;
   }
   return ret;
}

ll powMod(ll a, ll b, ll c){
   ll ret = 1, pib = a;
   while(b > 0){
      if( b & 1 ) ret = mulMod(ret, pib, c);
      pib = mulMod(pib, pib, c);
      b >>= 1;
   }
   return ret;
}

bool MillerRobin(ll num, int it = 30){
   if( num < 2 ) return false;
   if( num < 4 ) return true;
   if( not ( num & 1 ) ) return false;
   ll s = num - 1;
   while( not ( s & 1 ) ) s >>= 1;
   while(it--){
      ll rd = rand() % ( num - 1 ) + 1, pib = s; 
      ll ret = powMod(rd, pib, num);
      if( ret == -1 or ret == 1 ) continue;
      while( pib != num - 1 and ret != 1 and ret != num - 1 ){
         ret = mulMod(ret, ret, num);
         pib <<= 1;
      }
      if( ret != num - 1 ) return false;
   }
   return true;
}

ll gcd(ll a, ll b){
   return b == 0 ? a : gcd(b, a % b);
}

ll PollardRho(ll num){
   int i = 0, k = 2;
   ll ret = 3, pib = 3, d;
   while(++i){
      ret = mulMod(ret, ret, num) + num - 1;
      if( ret >= num ) ret -= num;
      if( pib - ret >= 0 ) d = gcd(pib - ret, num);
      else d = gcd(ret - pib, num);
      if( d != 1 and d != num ) return d;
      if( i == k ) pib = ret, k <<= 1;
   }
}

void GetFactors(){
   for(int i = 0; prime[i] * prime[i] <= n and n != 1 and i < prime.size(); i++)
      while( n % prime[i] == 0 ){
         n /= prime[i];
         printf( first ? "%lld" : " %lld", prime[i]);
         first = false;
      }
}

void solve(){
   first = true;
   if( n < L1 ){
      if( is_prime[n] ) printf("%lld", n);
      else{
         GetFactors();
         if( n != 1 ) printf(first ? "%lld" : " %lld", n);
      }
   }
   else if( n < L2 ){
      GetFactors();
      if( n != 1 ) printf(first ? "%lld" : " %lld", n);
   }
   else{
      if( MillerRobin(n) ) printf("%lld", n);
      else{
         GetFactors();
         if( n != 1 ){
            if( MillerRobin(n) ) printf(first ? "%lld" : " %lld", n);
            else{
               ll d = PollardRho(n);
               if( d > n / d ) d = n / d;
               printf(first ? "%lld %lld" : " %lld %lld", d, n / d);
            }
         }
      }
   }
   putchar('\n');
}

int main(){
   sieve();
   scanf("%d", &tc);
   while(tc--){
      scanf("%lld", &n);
      solve();
   }
   return(0);
}
