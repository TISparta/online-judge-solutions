#include <bits/stdc++.h>

using namespace std;

const int LEN = 55, SIZE = 105;

int tc, n, m;

struct DNA{
   char word[LEN];
   int measure;
   void unsortedness(){
      measure = 0;
      for(int i = 0; i < m; i++)
         for(int j = 0; j < i; j++)
            if( word[j] > word[i] ) measure++;
   }
   bool operator < (const DNA& other) const{
      return measure < other.measure;
   }
}v[SIZE];

int main(){
   scanf("%d", &tc);
   while(tc--){
      scanf("%d %d\n", &m, &n);
      for(int it = 0; it < n; it++){
         scanf("%s", v[it].word);
         v[it].unsortedness();
      }
      stable_sort(v, v + n);
      for(int it = 0; it < n; it++)
         printf("%s\n", v[it].word);
      if(tc) putchar('\n');
   }
   return(0);
}
