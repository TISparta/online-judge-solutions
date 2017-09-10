#include <bits/stdc++.h>

using namespace std;

int n, s[25], f[25], p, ans;

inline int position(int num){
   for(int i = 0; i < n; i++)
      if(f[i] == num) return i;
}

inline void minMov(int i){
   p = position(s[i]);
   ans += p - i;
   for(int ct = p; ct > i; ct--)
      swap(f[ct], f[ct - 1]);
}

int main(){
   while(scanf("%d", &n) == 1){
      ans = 0;
      for(int i = 0; i < n; i++) scanf("%d", &s[i]);
      for(int i = 0; i < n; i++) scanf("%d", &f[i]);
      for(int i = 0; i < n; i++) minMov(i);
      printf("%d\n", ans);
   }
   return(0);
}
