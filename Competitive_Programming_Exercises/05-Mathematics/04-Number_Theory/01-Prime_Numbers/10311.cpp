#include <bits/stdc++.h>

#define SIZE 100000010

using namespace std;

bool is_prime[SIZE];
vector<int>prime;
int n, a, b;
bool found;

void sieve(){
   memset(is_prime, true, sizeof is_prime);
   is_prime[0] = is_prime[1] = false;
   for(long long it1 = 2; it1 < SIZE; it1++){
      if(is_prime[it1]){
         for(long long it2 = it1 * it1; it2 < SIZE; it2 += it1)
            is_prime[it2] = false;
         prime.push_back(it1);
      }
   }
}

int main(){
   sieve();
   while(~scanf("%d",&n)){
      found = false;
      if(n&1){
         if( n > 2 and is_prime[ n - 2]){
            found = true;
            a = 2, b = n - 2;
         }
      }
      else{
         int pos = lower_bound(prime.begin(), prime.end(), n/2) - prime.begin();
         for(int it = pos; not found and it>=0; it--)
            if( is_prime[ n - prime[it] ] and n != 2 * prime[it] ) found = true, a = prime[it], b = n - prime[it];
      }
      if(found==false) printf("%d is not the sum of two primes!\n", n);
      else printf("%d is the sum of %d and %d.\n", n, min(a, b), max(a, b));
   }
   return(0);
}
