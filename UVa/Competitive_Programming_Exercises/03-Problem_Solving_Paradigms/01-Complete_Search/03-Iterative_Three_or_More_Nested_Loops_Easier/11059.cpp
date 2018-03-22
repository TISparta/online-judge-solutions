#include <bits/stdc++.h>

using namespace std;

long long n, v[20], _max, tmp, tc;

int main(){
   while(scanf("%lld",&n) == 1){
      _max = 0;
      for(int i = 0; i < n; i++) scanf("%lld", &v[i]);
      for(int i = 0; i < n; i++){
         tmp = v[i];
         _max = max(_max, tmp);
         for(int j = i + 1; j < n; j++){
            tmp *= v[j];
            _max = max(_max, tmp);
         }
      }
      printf("Case #%lld: The maximum product is %lld.\n\n", ++tc, _max);
   }
   return(0);
}
