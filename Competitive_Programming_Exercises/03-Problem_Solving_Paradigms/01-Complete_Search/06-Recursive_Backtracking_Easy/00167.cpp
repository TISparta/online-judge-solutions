#include <bits/stdc++.h>

using namespace std;

int t;
bool ok;
vector <int> x, ans[200];

void f(int col){
   if(col == 8){
      ans[t++] = x;
      return;
   }
   for(int i = 0; i < 8; i++){
      ok = true;
      for(int j = 0; j < x.size(); j++)
         if(x[j] == i || abs(col - j) == abs(x[j] - i)){
            ok = false;
            break;
         }  
   if(ok){
      x.push_back(i);
      f(col + 1);
      x.pop_back();
   }
   }
}

int main(){
   f(0);
   int a[8][8];
   int maxi, sum,k;
   cin >> k;
   while(k--){
      maxi = 0;
      for(int i = 0; i < 8; i++)
         for(int j = 0; j < 8; j++)
            scanf("%d", &a[i][j]);
      for(int i = 0; i < t; i++){
         sum = 0;
         for(int j = 0; j < 8; j++)
            sum += a[j][ans[i][j]];
         maxi = max(sum, maxi);
      }
      printf("%5d\n", maxi);
   }

   return(0);
}
