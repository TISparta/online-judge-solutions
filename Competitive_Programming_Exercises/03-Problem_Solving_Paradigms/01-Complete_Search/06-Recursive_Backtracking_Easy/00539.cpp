#include <bits/stdc++.h>

using namespace std;

#define N 1000

int nod, edg;
int a[N][N];
int maxi = 0;

void f(int k, int ans){
   maxi = max(ans,maxi);
   for(int i = 0; i < nod; i++)
      if(a[k][i] && i != k){
         a[k][i] = 0;
         a[i][k] = 0;
         f(i, ans + 1);
         a[k][i] = 1;
         a[i][k] = 1;
      }
}

int main(){
   int temp1, temp2;
   while(scanf("%d%d", &nod, &edg), nod && edg){
      memset(a, 0, sizeof a);
      for(int i = 0; i < edg; i++){
         cin >> temp1 >> temp2,
         a[temp1][temp2] = 1;
      }
      for(int i=0;i<nod;i++)
         f(i,0);
      cout << maxi << endl;
      maxi = 0;
   }
   return(0);
}
