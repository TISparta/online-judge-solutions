#include <bits/stdc++.h>

#define SIZE 110

using namespace std;

int n, v[SIZE][SIZE], row[SIZE], column[SIZE], ct;
pair <int, int> ans;
bool corrupt;

int main(){
   while(scanf("%d", &n), n){
      memset(row, 0, sizeof row);
      memset(column, 0, sizeof column);
      ct = 0, corrupt = false;
      for(int i = 1; i <= n; i++)
         for(int j = 1; j <= n; j++) scanf("%d", &v[i][j]);
      for(int i = 1; i <= n; i++)
         for(int j = 1; j <= n; j++) row[i] ^= v[i][j];
      for(int j = 1; j <= n; j++)
         for(int i = 1; i <= n; i++) column[j] ^= v[i][j];
      for(int i = 1; i <= n; i++)
         for(int j = 1; j <= n; j++)
            if(row[i] != column[j]) corrupt = true;
            else if(row[i] * column[j]) ans = make_pair(i, j), ct++;
      if(ct == 1) printf("Change bit (%d,%d)\n", ans.first, ans.second);
      else if(ct >= 2 || corrupt) puts("Corrupt");
      else puts("OK");
   }
   return(0);
}
