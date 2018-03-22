#include <bits/stdc++.h>

#define SIZE 105

using namespace std;

int n, d, r, morning[SIZE], evening[SIZE], ans;

int main(){
   while(scanf("%d %d %d", &n, &d, &r), n | d | r){
      for(int i = 0; i < n; i++) scanf("%d", &morning[i]);
      for(int i = 0; i < n; i++) scanf("%d", &evening[i]);
      sort(morning, morning + n);
      sort(evening, evening + n);
      ans = 0;
      for(int i = 0; i < n; i++)
         if(morning[i] + evening[n - i - 1] > d)
               ans += (morning[i] + evening[n - i - 1] - d) * r;
      printf("%d\n", ans);
   }
   return(0);
}
