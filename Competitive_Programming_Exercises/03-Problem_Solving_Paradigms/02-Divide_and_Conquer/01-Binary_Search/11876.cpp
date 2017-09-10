#include <bits/stdc++.h>

#define LIM 1000000

using namespace std;

bitset <LIM+10> prime;
vector <int> p;

void sieve(){
   prime[0] = prime[1] = true;
   p.push_back(2);
   for(int i = 3; i <LIM; i += 2){
      if(!prime[i]){
         for(int j = i + i; j < LIM; j += i)
            prime[j] = true;
         p.push_back(i);
      }
      prime[i + 1] = true;
   }
}

int NOD(int n){
   if(!prime[n]) return 2;
   int ct, cd=1;
   for(int i = 0; n != 1; i++){
      ct = 1;
      while(!( n % p[i]))
         ct++, n /= p[i];
      cd *= ct;
   }
   return cd;
}

int main(){
   sieve();
   int c, t = 0,n, m, ans;
   vector <int> seq;
   seq.push_back(1);
   for(int i=1; seq[i - 1] < 1000000; i++)
      seq.push_back(seq[i - 1] + NOD(seq[i - 1]));
   scanf("%d", &c);
   while(c--){
      scanf("%d %d", &n, &m);
      printf("Case %d: ", ++t);
      ans = upper_bound(seq.begin(), seq.end(), m) - seq.begin() - (upper_bound(seq.begin(), seq.end(), n - 1) - seq.begin());
      printf("%d\n", ans);
   }
   return(0);
}
