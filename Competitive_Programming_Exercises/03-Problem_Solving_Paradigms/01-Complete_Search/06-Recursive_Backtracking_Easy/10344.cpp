#include <bits/stdc++.h>

using namespace std;

vector <int> a(5), b[81], y, x;
bool ind, proof;
int k, tmp;
bool visited[5];

void f(int ct){
   if(ct == 4){
      b[k++] = y;
      return;
   }
   for(int i = 1; i <= 3; i++){
      y.push_back(i);
      f(ct + 1);
      y.pop_back();
   }
}

void h(int ct){
   if(ind)
      return;
   if(ct == 5){
      for(int i = 0; i < 81;i++){
         tmp = x[0];
         for(int j = 0; j < 4; j++){
            if(b[i][j] == 1)
               tmp += x[j + 1];
            else if(b[i][j] == 2)
               tmp -= x[j + 1];
            else if(b[i][j] == 3)
               tmp *= x[j + 1];
         }
         if(tmp == 23){
            ind = true;
            return;
         }
      }
      return;
   }
   for(int i = 0; i < 5; i++)
      if(!visited[i]){
         visited[i] = true;
         x.push_back(a[i]);
         h(ct + 1);
         visited[i] = false;
         x.pop_back();
      }
}

int main(){
   f(0);
   while(scanf("%d %d %d %d %d", &a[0], &a[1], &a[2], &a[3], &a[4]), a[0] || a[1] || a[2] || a[3] || a[4]){
      ind = false;
      h(0);
      printf( ind ? "Possible\n" : "Impossible\n");
   }
   return(0);
}
