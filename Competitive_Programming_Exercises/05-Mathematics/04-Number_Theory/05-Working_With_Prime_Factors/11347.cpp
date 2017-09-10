#include <bits/stdc++.h>

#define  SIZE 1010

using namespace std;

bool is_prime[SIZE];
vector <int> prime;
int tc, Factor[SIZE][SIZE], num, v[SIZE];
char s[SIZE];
long long ans;
double aux;

void sieve(){
   memset(is_prime, true, sizeof is_prime);
   is_prime[0] = is_prime[1] = false;
   for(int it1 = 2; it1 < SIZE; it1++)
      if( is_prime[it1] ){
         for(int it2 = it1 * it1; it2 < SIZE; it2 += it2)
            is_prime[it2] = false;
         prime.push_back(it1);
      }
}

void GetFactors(){
   for(int num = 1; num < SIZE; num++){
      int pib = num;
      for(int it = 0; it < prime.size() and pib != 1; it++)
         if( pib % prime[it] == 0 ){
            int ct = 0;
            while( pib % prime[it] == 0 ) pib /= prime[it], ct++;
            Factor[num][it] = ct;
         }
   }
}

int main(){
   sieve();
   GetFactors();
   scanf("%d\n", &tc);
   for(int t = 1; t <= tc; t++){
      scanf("%s", s);
      int k = 0;
      for(int it = 0; s[it]; it++) if( s[it] == '!' ) k++;
      num = 0;
      for(int it = 0; s[it] != '!'; it++) num = num * 10 + ( s[it] - '0' );
      memset(v, 0, sizeof v);
      for(int n = num; n > 1; n -= k)
         for(int it = 0; it < SIZE; it++) v[it] += Factor[n][it];
      ans = aux = 1;
      for(int it = 0; it < SIZE; it++) ans *= v[it] + 1, aux *= v[it] + 1;
      if( aux > 1e18 ) printf("Case %d: Infinity\n", t);
      else printf("Case %d: %lld\n", t, ans);
   }
   return(0);
}
