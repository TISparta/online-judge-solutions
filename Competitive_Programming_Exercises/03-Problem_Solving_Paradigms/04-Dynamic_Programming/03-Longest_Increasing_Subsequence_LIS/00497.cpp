#include <bits/stdc++.h>

using namespace std;

int tc, n, v[10010], lis[10010], path[10010], idxMax, ans;
char s[10];

void printPath(int idx){
   if(path[idx] == -1){
      printf("%d\n", v[idx]);
      return;
   }
   printPath(path[idx]);
   printf("%d\n", v[idx]);
}

int main(){
   scanf("%d\n", &tc);
   while(tc--){
      n = idxMax = 0, ans = 1;
      while(cin.getline(s, 10)){        
         if(sscanf(s,"%d", &v[n]) == -1) break;
         lis[n] = 1, path[n++] = -1;
      }
      for(int i = 1; i < n; i++){
         for(int j = 0; j < i; j++)
            if(v[i] > v[j] && lis[i] < lis[j] + 1)
               lis[i] = lis[j] + 1, path[i] = j;
         if(lis[i] > ans) ans = lis[i], idxMax = i;
      }
      printf("Max hits: %d\n", ans);
      printPath(idxMax);
      if(tc) putchar('\n');
   }
   return(0);
}
