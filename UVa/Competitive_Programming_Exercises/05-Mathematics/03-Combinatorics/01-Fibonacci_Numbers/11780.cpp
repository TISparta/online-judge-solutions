#include <bits/stdc++.h>

#define LIM 17

using namespace std;

int n, tmp;
vector <int> fibo;
float km, ans;

int main(){
   fibo.push_back(0);
   fibo.push_back(1);
   for(int i = 2; i < LIM; i++)
      fibo.push_back(fibo[i - 1] + fibo[i - 2]);
   while(scanf("%d", &n), n){
      ans = 0;
      km = 1.6 * n;
      while(n){
         tmp = fibo[lower_bound(fibo.begin(), fibo.end(), n + 1) - fibo.begin() - 1];
         ans += ceil(1.6 * tmp);
         n -= tmp;
      }
      ans = abs(km - ans);
      while(ans > 0.5)
         ans -= 1;
      if(ans == 0.60)
         ans = 1 - ans;
      else if(ans == 0.80)
         ans = 1 - ans;
      printf("%.2f\n", abs(ans));
   }
   return(0);
}
