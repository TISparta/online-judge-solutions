#include <bits/stdc++.h>

using namespace std;

int n, tc, d, used[10], p;
vector <int> v, ans((int)1e7);

inline bool isRunNumber(int num){
   v.clear(), d = 0;
   memset(used, 0, sizeof used);
   while(num)
      v.push_back(num % 10), num /= 10, d++;
   reverse(v.begin(), v.end());
   p = 0;
   for(int i = 0; i < d; i++){
      p = (p + v[p]) % d;
      used[v[p]]++;
      if(used[v[p]] > 1) return false;
   }
   if(p != 0) return false;
   return true;
}

int main(){
   for(int i= (int)1e7; i >= 10; i--)
      if(isRunNumber(i)) ans[i] = i;
      else ans[i] = ans[i + 1];
   while(scanf("%d", &n), n)
      printf("Case %d: %d\n", ++tc, ans[n]);
   return(0);
}
