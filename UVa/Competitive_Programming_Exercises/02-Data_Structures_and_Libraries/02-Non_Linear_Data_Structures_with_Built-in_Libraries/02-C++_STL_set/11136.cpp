#include <bits/stdc++.h>

using namespace std;

long long n, bills, num, _min, _max, ans;
multiset <long long> ::iterator it;

int main(){
   while(scanf("%lld", &n), n){
      multiset <long long> v;
      ans = 0;
      while(n--){
         scanf("%lld", &bills);
         while(bills--) scanf("%lld", &num), v.insert(num);
         _min = *v.begin(), v.erase(v.begin());
         it = --v.end(), _max = *it, v.erase(it);
         ans += _max - _min;
      }
      printf("%lld\n", ans);
   }
   return(0);
}
