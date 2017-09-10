#include <bits/stdc++.h>

using namespace std;

int n, num, sum, a, b;

int main(){
   while(scanf("%d",&n), n){
      priority_queue <int> v;
      sum = 0;
      for(int i = 0; i < n; i++) scanf("%d", &num), v.push(-num);
      for(int i = 1;i < n; i++){
         a = v.top(), v.pop();
         b = v.top(), v.pop();
         sum -= a + b;
         v.push(a + b);
      }
      printf("%d\n", sum);
   }
   return(0);
}
