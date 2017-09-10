#include <bits/stdc++.h>

using namespace std;

int tc, x, y, lim;
vector <int> a[20], b[20];

int main(){
   a[0].push_back(1);
   for(int i = 1; i < 20; i++){
      lim = 1 << i - 1;
      for(int j = 0; j < lim; j++)
         a[i].push_back(a[i - 1][j] << 1);
      for(int j = 0; j < lim; j++)
         a[i].push_back((a[i - 1][j] << 1) + 1);
   }
   scanf("%d", &tc);
   while(tc--){
      scanf("%d %d", &x, &y);
      printf("%d\n",a[x - 1][y - 1]);
   }
   return(0);
}
