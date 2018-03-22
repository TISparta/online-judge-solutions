#include <bits/stdc++.h>

using namespace std;

const int SIZE = 55;

int tc, N, v[SIZE];

int BubbleSort(){
   int ans = 0;
   for(int i = 0; i < N; i++)
      for(int j = 0; j < i; j++)
         if( v[j] > v[i] ) swap(v[j], v[i]), ans++;
   return ans;
}

int main(){
   scanf("%d", &tc);
   while(tc--){
      scanf("%d", &N);
      for(int it = 0; it < N; it++)
         scanf("%d", v + it);
      printf("Optimal train swapping takes %d swaps.\n", BubbleSort());
   }
   return(0);
}
