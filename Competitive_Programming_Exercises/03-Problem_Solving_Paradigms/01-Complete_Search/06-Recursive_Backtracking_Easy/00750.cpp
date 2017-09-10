#include <bits/stdc++.h>

using namespace std;

vector <int> x, ans[100];
bool ok;
int k, t;

void f(int col){
   if(col == 8){
      ans[k++] = x;
      return;
   }
   for(int i = 1; i <= 8; i++){
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
   int n, m, c;
   scanf("%d", &c);
   while(c--){
      scanf("%d%d", &n, &m);
      printf("SOLN       COLUMN\n");
      printf(" #      1 2 3 4 5 6 7 8\n\n");
      t = 0;
      for(int i = 0; i < k; i++)
         if(ans[i][m - 1] == n){
            printf("%2d      ", ++t);
            for(int j = 0; j < 8; j++){
               printf("%d", ans[i][j]);
               if(j != 7)
                  putchar(' ');
            }
            putchar('\n');
         }
      if(c)
         putchar('\n');
   }
   return(0);
}
