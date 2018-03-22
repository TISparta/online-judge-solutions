#include <bits/stdc++.h>

#define SIZE 110
#define LIM 110
#define LIM_SIEVE 1010

using namespace std;

char line[LIM], *p;
int v[SIZE], ct, num;
bool is_prime[LIM_SIEVE];
vector<int>prime;
vector< pair<int, int> >Factors;

void sieve(){
   memset(is_prime, true, sizeof is_prime);
   is_prime[0] = is_prime[1] = false;
   for(long long it1 = 2; it1 < LIM_SIEVE; it1++)
      if( is_prime[it1] ){
         for(long long it2 = it1 * it1; it2 < LIM_SIEVE; it2 += it1)
            is_prime[it2] = false;
         prime.push_back(it1);
      }
}

void primeFactors(int N){
   Factors.clear();
   for(int it = 0; it < prime.size() and prime[it] * prime[it] <= N and N != 1; it++){
      int e = 0;
      while( N % prime[it] == 0 ) N /= prime[it], e++;
      if(e) Factors.push_back( make_pair(prime[it], e) );
   }
   if(N != 1) Factors.push_back( make_pair(N, 1) );
}

int main(){
   sieve();
   while(cin.getline(line, LIM), line[0] != '0'){
      p = strtok(line, " ");
      ct = 0;
      while(p) v[ct++] = atoi(p), p = strtok(NULL, " ");
      num = 1;
      for(int it = 1; it < ct; it += 2)
         for(int e = 0; e < v[it]; e++)
            num  *= v[it - 1];
      primeFactors(num - 1);
      for(int it = Factors.size() - 1; it >= 0; it--)
         printf(it == 0 ? "%d %d\n" : "%d %d ", Factors[it].first, Factors[it].second);
   }
   return(0);
}
