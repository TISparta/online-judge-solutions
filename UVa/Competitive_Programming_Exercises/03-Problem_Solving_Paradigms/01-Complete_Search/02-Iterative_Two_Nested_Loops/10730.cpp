#include <bits/stdc++.h>

using namespace std;

vector <int> v(10010);
bool visited[10010];
int n, pib;

bool isAntiarithmetic(){
   memset(visited, false, sizeof visited);
   for(int i = 0; i < n; i++){
      for(int j = i + 1;j < n; j++){
         visited[v[j]] = true;
         pib = v[i] + v[j];
         if(!(pib&1) && visited[pib >> 1])
            return false;
      }
      for(int j = i + 1; j < n; j++)
         visited[v[j]] = false;
   }
   return true;
}

int main(){
   while(scanf("%d:", &n), n){
      for(int i = 0; i < n; i++) scanf("%d", &v[i]);
      puts( isAntiarithmetic() ? "yes" : "no");     
   }
   return(0);
}
