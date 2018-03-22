#include <bits/stdc++.h>

#define SIZE 10010

using namespace std;

bool is_prime[SIZE];
vector <int> prime;
int tc, M, N, FFactors[SIZE][SIZE], ans;
vector < pair <int, int> > Factor;

void sieve(){
   memset(is_prime, true, sizeof is_prime);
   for(long long it1 = 2; it1 < SIZE; it1++)
      if( is_prime[it1] ){
         for(long long it2 = it1 * it1; it2 < SIZE; it2 += it1)
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
   Factor.clear();
   for(int it = 0; it < prime.size() and prime[it] <= n; it++)
      if( n % prime[it] == 0 ){
         int ct = 0;
         while( n % prime[it] == 0 ) n /= prime[it], ct++;
         Factor.push_back( make_pair( prime[it], ct ) );
      }
}

void solve(){
   ans = INT_MAX;
   for(int it = 0; it < Factor.size(); it++)
      ans = min(ans, FFactors[N][Factor[it].first] / Factor[it].second);
   if( ans == 0 ) puts("Impossible to divide");
   else printf("%d\n", ans);
}

int main(){
   sieve();
   FactorialFactors();
   scanf("%d", &tc);
   for(int t = 1; t <= tc; t++){
      scanf("%d %d", &M, &N);
      GetFactors(M);
      printf("Case %d:\n", t);
      solve();
   }
   return(0);
}
