#include <bits/stdc++.h>

using namespace std;

int a[10][100];
bool b[10][100];
vector <int> aux;

int main(){
   int c,n,m,ind,sum;
   scanf("%d",&c);
   while(c--){
      ind = 1;
      memset(b, false, sizeof b);
      scanf("%d%d",&n,&m);
      for(int i = 0;i < n; i++)
         for(int j = 0; j < m; j++)
            scanf("%d", &a[i][j]);
      for(int i = 0; i < m; i++){
         sum = 0;
         for(int j = 0; j < n; j++)
            sum += a[j][i];
         if(sum != 2) ind = 0;
      }
      for(int j = 0; j < m; j++){
         for(int i = 0; i < n; i++)
            if(a[i][j] == 1)
               aux.push_back(i);
         if(b[aux[0]][aux[1]] == true) ind = 0;
         b[aux[0]][aux[1]] = true;
         aux.clear();
      }
      printf(ind ? "Yes\n" : "No\n");
   }
   return(0);
}
