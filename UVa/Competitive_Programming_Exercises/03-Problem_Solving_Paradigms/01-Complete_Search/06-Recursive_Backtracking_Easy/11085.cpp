#include <bits/stdc++.h>

using namespace std;

vector <int> ans[1000];
vector <int> x;
int a[8], t;

void f(int col){
   if(col == 8){
      ans[t++] = x;
      return;
   }
   for(int i = 0 ; i < 8 ; i++){
      bool ok = true;
      for(int j = 0; j < x.size(); j++)
         if(x[j] == i || abs(col - j) == abs(x[j] - i)){
            ok = false;
            break;
         }
      if(ok == true){
         x.push_back(i);
         f(col + 1);
         x.pop_back();
      }
   }
}

int main(){
   int m, s, l = 1;
   f(0);
   while(scanf("%d %d %d %d %d %d %d %d", &a[0], &a[1], &a[2], &a[3], &a[4], &a[5], &a[6], &a[7]) == 8){
      m = 9;
      for(int k = 0; k < t; k++){
         s = 0;
         for(int j = 0; j < 8; j++)
            if((a[j] - 1) != ans[k][j])
               s++;
      m = min(s, m);
      }
      cout << "Case " << l << ": " << m << endl;
      l++;
   }
   return(0);
}
