#include <bits/stdc++.h>

using namespace std;

const int SIZE = 1005;

int N, v[SIZE];

int InsertionSort(){
   int ans = 0;
   for(int i = 1; i < N; i++){
      int key = v[i], j;
      for(j = i - 1; j >= 0 and v[j] > key; j--)
         v[j + 1] = v[j], ans++;
      v[j + 1] = key;
   }
   return ans;
}

int main(){
   while(~scanf("%d", &N)){
      for(int it = 0; it < N; it++)
         scanf("%d", v + it);
      printf("Minimum exchange operations : %d\n", InsertionSort());
   }
   return(0);
}
