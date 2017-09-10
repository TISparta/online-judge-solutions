#include <bits/stdc++.h>

#define SIZE 100010

using namespace std;

bool is_prime[SIZE];
vector <int> prime;
vector < pair <int, int> > Factor;
int N, M;

void sieve(){
   memset(is_prime, true, sizeof is_prime);
   is_prime[0] = is_prime[1] = false;
   for(long long it1 = 2; it1 < SIZE; it1++)
      if( is_prime[it1] ){
         for(long long it2 = it1 * it1; it2 < SIZE; it2 += it1)
            is_prime[it2] = false;
         prime.push_back(it1);
      }
}

void GetFactors(int n){
   Factor.clear();
   if( n == 0 ) return;
   for(int it = 0; it < prime.size() and prime[it] * prime[it] <= n and n != 1; it++)
      if( n % prime[it] == 0 ){
         int ct = 0;
         while( n % prime[it] == 0 ) n /= prime[it], ct++;
         Factor.push_back( make_pair(prime[it], ct) );
      }
   if( n != 1 ) Factor.push_back( make_pair(n, 1) );
}

bool solve(){
   for(int it = 0; it < Factor.size(); it++){
      int ct = 0;
      for(long long p = Factor[it].first; N / p; p *= Factor[it].first)
         ct += N / p;
      if( ct < Factor[it].second ) return false;
   }
   return true;
}

int main(){
   sieve();
   while(scanf("%d %d",&N, &M)==2){
      GetFactors(M);
      if( solve() ) printf("%d divides %d!\n", M, N);
      else printf("%d does not divide %d!\n", M, N);
   }
   return(0);
}
