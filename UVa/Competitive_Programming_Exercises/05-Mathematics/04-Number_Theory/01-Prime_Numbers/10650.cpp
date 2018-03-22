#include <bits/stdc++.h>

#define SIZE 32000
#define LIM 200

using namespace std;

bool is_prime[SIZE];
vector<int>prime;
vector<int>determinate[LIM];
int x, y, z;

void sieve(){
   memset(is_prime, true, sizeof is_prime);
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
   for(int it = 0; it < prime.size() - 1; ){
      int dis = prime[it + 1] - prime[it], j;
      for(j = it + 1; j < prime.size() - 1; )
         if(prime[j + 1] - prime[j] == dis) j++;
         else break;
      if(j - it >=2){
         for(int i = it; i <= j; i++)
            determinate[z].push_back( prime[i] );
         z++;
      }
      it = j;
   }
   while(scanf("%d %d",&x, &y), x|y){
      if(x>y) swap(x, y);
      for(int it = 0; it < z; it++){
         if(determinate[it][0] >= x and determinate[it].back() <= y)
            for(int i = 0; i < determinate[it].size(); i++)
               printf(i!=determinate[it].size() - 1 ? "%d " : "%d\n", determinate[it][i]); 
      }
   }
   return(0);
}
