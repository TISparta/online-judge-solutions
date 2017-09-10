#include <bits/stdc++.h>

#define pb push_back

using namespace std;

int tc, n, max_height, foo1, foo2, foo3;
int memo[90];

struct tri{
   int x;
   int y;
   int z;
} tmp;

vector <tri> v;

int dp(int p){
   if(memo[p] != -1) return memo[p];
   int ans = 0;
   for(int i = 0; i < n; i++)
      if( (v[i].x < v[p].x && v[i].y < v[p].y) ||
          (v[i].y < v[p].x && v[i].x < v[p].y) )
         ans = max(ans, dp(i));
   memo[p] = ans + v[p].z;
   return memo[p];
}

int main(){
   while(scanf("%d", &n), n){
      max_height = 0;
      memset(memo, -1, sizeof memo);
      v.clear();
      for(int i = 0; i < n; i++){
         scanf("%d %d %d", &foo1, &foo2, &foo3);
         tmp.x = foo1, tmp.y = foo2, tmp.z = foo3;
         v.pb(tmp);
         tmp.x = foo2, tmp.y = foo3, tmp.z = foo1;
         v.pb(tmp);
         tmp.x = foo3, tmp.y = foo1, tmp.z = foo2;
         v.pb(tmp);        
      }
      n *= 3;
      for(int i = 0; i < n; i++)
         max_height = max(max_height, dp(i));
      printf("Case %d: maximum height = %d\n", ++tc, max_height);
   }
   return(0);
}
