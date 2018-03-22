#include <bits/stdc++.h>

using namespace std;

int tc, ct, n;
vector <int> v(1005);

int main(){
   scanf("%d", &tc);
   while(tc--){
      scanf("%d", &n); ct = 0;
      for(int i = 0; i < n; i++) scanf("%d", &v[i]);
      for(int i = 1; i < n; i++)
         for(int j = 0; j < i; j++)
            if(v[j] <= v[i]) ct++;
      printf("%d\n", ct);
   }
   return(0);
}
