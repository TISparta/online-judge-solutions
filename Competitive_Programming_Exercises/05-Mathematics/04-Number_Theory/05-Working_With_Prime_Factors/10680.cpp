#include <bits/stdc++.h>

#define SIZE 1000010

using namespace std;

long long table[SIZE];
int n;
const int MOD = 1000;

int main(){
   for(int it = 1; it < SIZE; it++) table[it] = it;
   for(int it1 = 2; it1 < SIZE; it1++)
      for(int it2 = 2 * it1; it2 < SIZE; it2 += it1)
         table[it2] /= table[it1];
   for(int it = 2; it < SIZE; it++){
      table[it] *= table[it - 1];
      while( table[it] % 10 == 0 ) table[it] /= 10;
      table[it] %= MOD;
   }
   while(scanf("%d",&n), n)
      printf("%lld\n", table[n] % 10 );
}
