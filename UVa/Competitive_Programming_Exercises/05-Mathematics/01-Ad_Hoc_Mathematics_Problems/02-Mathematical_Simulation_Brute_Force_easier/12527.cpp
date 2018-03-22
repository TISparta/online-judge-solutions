#include <bits/stdc++.h>

using namespace std;

bool rep_digit(int n){
   vector <int> x;
   while(n)
      x.push_back(n % 10), n /= 10;
   for(int i = 0; i < x.size(); i++)
      for(int j= i + 1;j < x.size(); j++)
         if(x[i] == x[j])
            return false;
   return true;
}

int main(){
   int n, m, ans;
   while(scanf("%d %d", &n, &m) == 2){
      ans = 0;
      for(int i = n; i <= m; i++)
         ans += rep_digit(i);
      printf("%d\n", ans);
   }
   return(0);
}
