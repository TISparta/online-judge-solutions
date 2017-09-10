#include <bits/stdc++.h>

#define SIZE 10

using namespace std;

int tc, k, u[SIZE], v[SIZE], _min, _max, j;
bool taken[SIZE];

int main(){
   scanf("%d",&tc);
   while(tc--){
      memset(taken, false, sizeof taken);
      _min = _max = 0;
      scanf("%d", &k);
      for(int i = 0; i < k; i++) scanf("%d", &u[i]);
      for(int i = 0; i < k; i++) scanf("%d", &v[i]), _min += v[i];
      for(int i = 0; i < k; i++){
         for(j = 0; j < k; j++)
            if(taken[j] == false && u[i] == v[j])
               taken[j] = true, j = k + 1;
         if(j == k) _min += u[i];
      }
      for(int i = 0; i < k; i++)
         for(int j = 0; j < k; j++)
            _max += min(u[i], v[j]);
      printf("Matty needs at least %d blocks, and can add at most %d extra blocks.\n", _min, _max - _min);
   }
   return(0);
}
