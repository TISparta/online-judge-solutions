#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 10010;

int N, ways[MAX_N];
bool is_prime[MAX_N];
vector <int> prime;

void sieve(){
   memset(is_prime, true, sizeof is_prime);
   is_prime[0] = is_prime[1] = false;
   for(int i = 2; i < MAX_N; i++)
      if( is_prime[i] ){
         for(int j = i * i; j < MAX_N; j += i)
            is_prime[j] = false;
         prime.push_back(i);
      }
}

void precomputation(){
   sieve();
   for(int i = 0; i < prime.size(); i++)
      for(int j = i, sum = 0; j < prime.size() and sum + prime[j] < MAX_N; j++)
         sum += prime[j], ways[sum]++;
}

int main(){
   precomputation();
   while(scanf("%d", &N), N) printf("%d\n", ways[N]);
   return(0);
}
