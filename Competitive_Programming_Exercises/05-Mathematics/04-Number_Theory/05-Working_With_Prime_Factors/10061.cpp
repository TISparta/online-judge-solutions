#include <bits/stdc++.h>

#define SIZE 30

using namespace std;

bool is_prime[SIZE];
vector <int> prime;
vector < pair <int, int> > Factor;
int N, B;
const long double EPS = 1e-15;

void sieve(){
   memset(is_prime, true, sizeof is_prime);
   is_prime[0] = is_prime[1] = false;
   for(int it1 = 2; it1 < SIZE; it1++)
      if( is_prime[it1] ){
         for(int it2 = it1 * it1; it2 < SIZE; it2 += it1)
            is_prime[it2] = false;
         prime.push_back(it1);
      }
}

void GetFactors(int n){
   Factor.clear();
   for(int it = 0; it < prime.size() and prime[it] <= n and n != 1; it++)
      if( n % prime[it] == 0 ){
         int ct = 0;
         while( n % prime[it] == 0 ) n /= prime[it], ct++;
         Factor.push_back( make_pair(prime[it], ct) );
      }
   if( n != 1 ) Factor.push_back( make_pair(n, 1) );
}

int trailingZeros(){
   int zeros = INT_MAX;
   for(int it = 0; it < Factor.size(); it++){
      int p = Factor[it].first, e = 0;
      while( N / p ) e += N / p, p *= Factor[it].first;
      zeros = min(zeros, e / Factor[it].second);     
   }
   return zeros;
}

inline long double logB(long double a,long double base){
   return log10(a) / log10(base);
}

int NumberDigits(){
   long double digits = 0;
   for(int it = 2; it <= N; it++) digits += logB( it, B);
   return ceil( digits + EPS );
}

int main(){
   sieve();
   while(scanf("%d %d", &N, &B) == 2){
      GetFactors(B);
      printf("%d %d\n", trailingZeros(), NumberDigits());
   }
   return(0);
}
