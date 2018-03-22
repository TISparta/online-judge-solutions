#include <bits/stdc++.h>

#define SIZE 1005

using namespace std;

int tc, n, ans, v[SIZE];
long long sum;

int main(){
   scanf("%d", &tc);
   while(tc--){
      scanf("%d", &n);
      for(int i = 0; i < n; i++) scanf("%d", &v[i]);
      sum = 1;
      ans = (n == 1) ? 1 : 2;
      for(int i = 1; i < n - 1; i++)
         if(sum+v[i] < v[i + 1]) sum += v[i], ans++;
      printf("%d\n", ans);
   }
   return(0);
}
