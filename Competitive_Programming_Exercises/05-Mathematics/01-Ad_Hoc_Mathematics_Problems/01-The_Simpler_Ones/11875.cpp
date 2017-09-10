#include <bits/stdc++.h>

using namespace std;

int main(){
   int c, n, tmp, t = 0;
   vector <int> a;
   scanf("%d", &c);
   while(c--){
      scanf("%d", &n);
      for(int i = 0 ; i < n; i++)
         scanf("%d", &tmp), a.push_back(tmp);
      sort(a.begin(), a.end());
      printf("Case %d: %d\n", ++t, a[a.size() / 2]);
      a.clear();
   }
   return(0);
}
