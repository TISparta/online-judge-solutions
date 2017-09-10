#include <bits/stdc++.h>

using namespace std;

vector <int> ans;
vector <int> a;
vector <int> x;
int n, m, maxi = 0;

void f(int s, int k){
   if(k  == n + 1 )
      return;
   if( s  <= m   && s && s  >= maxi){
      maxi = max(maxi, s);
      ans = x;
   }
   x.push_back(a[k]);
   f(s + a[k], k + 1);
   x.pop_back();
   f(s, k + 1);

}

int main(){
   int temp;
   while(scanf("%d%d", &m, &n) == 2){
      maxi = 0;
      for(int i=0;i<n;i++){
         scanf("%d", &temp);
         a.push_back(temp);
      }
      f(0,0);
      for(int i = 0; i < ans.size(); i++)
         printf("%d ", ans[i]);
      printf("sum:%d\n", maxi);
      a.clear();
      x.clear();
   }
   return(0);
}
