#include <bits/stdc++.h>

using namespace std;

int tc, n, _min, tmp;
vector <int> v;

int main(){
   scanf("%d", &tc);
   while(tc--){
      scanf("%d", &n);
      v.resize(n); _min = INT_MAX;
      for(int i = 0; i < n; i++)
         scanf("%d", &v[i]);
      for(int i = 0; i < n; i++){
         tmp = 0;
         for(int j = 0; j < n; j++)
            tmp += abs(v[i] - v[j]);
         if(tmp < _min)
            _min = tmp;
      }
      printf("%d\n", _min);
   }
   return(0);
}
