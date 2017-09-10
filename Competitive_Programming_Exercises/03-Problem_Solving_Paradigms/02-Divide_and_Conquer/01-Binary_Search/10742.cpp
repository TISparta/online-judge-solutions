#include <bits/stdc++.h>

using namespace std;

int n, l, r, mid, ans, k, num, t;
bool p[1000000];
vector <int> prime;

int binary(int x){
   num = prime[x];
   l = x;
   r  = 78498;
   while(r - l > 1){
      mid = (l + r) / 2;
      if(num + prime[mid] <= n)
         l = mid;
      else
         r = mid;
   }
   return l - x;
}

int main(){
   prime.push_back(2);
   for(int i = 3; i < 1000000; i += 2)
      if(!p[i]){
         for(int j = i + i; j < 1000000; j += i)
            p[j] = true;
         prime.push_back(i);
      }
   while(scanf("%d", &n), n){
      ans = 0;
      for(int i = 0; i < 78498; i++){
         k = binary(i);
         if(k == 0)
            break;
         ans += k;
      }
      printf("Case %d: %d\n", ++t, ans);
   }
   return(0);
}
