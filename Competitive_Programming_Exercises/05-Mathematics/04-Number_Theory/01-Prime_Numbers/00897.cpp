#include <bits/stdc++.h>

#define SIZE 10000000

using namespace std;

bool is_prime[SIZE], ok;
vector<int>prime;
set<int>anagrammatic_prime;
string s, ans;
int n;

void sieve(){
   memset(is_prime, true, sizeof is_prime);
   is_prime[0] = is_prime[1] = false;
   for(long long it1 = 2; it1 < SIZE; it1++)
      if(is_prime[it1]){
         for(long long it2 = it1 * it1; it2 < SIZE; it2 += it1)
            is_prime[it2] = false;
         prime.push_back(it1);
      }
}

int main(){
   sieve();
   for(int it = 0; it < prime.size(); it++){
      s = to_string(prime[it]);
      vector<int>v;
      for(int i=0;i<s.size();i++) v.push_back(i);
      ok = true;
      do{
         string aux = s;
         for(int it = 0; it < aux.size(); it++)
            aux[it] = s[ v[it] ];
         if(not is_prime[stoi(aux)]) ok = false;
         if(not ok) break;
      }while(next_permutation(v.begin(),v.end()));
      if(ok) anagrammatic_prime.insert(prime[it]);
   }
   while(scanf("%d",&n),n){
      ans = to_string(*anagrammatic_prime.upper_bound(n));
      if(ans.size()==to_string(n).size()) printf("%s\n",ans.c_str());
      else puts("0");
   }
   return(0);
}
