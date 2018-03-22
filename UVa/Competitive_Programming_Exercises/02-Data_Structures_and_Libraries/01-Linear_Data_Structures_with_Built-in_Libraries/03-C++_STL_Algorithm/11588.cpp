#include <bits/stdc++.h>

#define SIZE 410

using namespace std;

int tc, R, C, M, N, abc[30], _max, sz;
char s[SIZE], ss[SIZE];

int main(){
   scanf("%d", &tc);
   for(int t = 1; t <= tc; t++){
      s[0] = '\0';
      memset(abc, 0, sizeof abc);
      _max = -1, sz = 0;
      scanf("%d %d %d %d\n", &R, &C, &M, &N);
      for(int i = 0; i < R; i++) scanf("%s", ss), strcat(s, ss);
      for(int i = 0; s[i]; i++) abc[s[i] - 'A']++;
      _max = -1;
      for(int i = 0; i < 26; i++)
         if(abc[i] > _max) _max = abc[i];
      for(int i = 0; s[i]; i++)
         if(abc[s[i] - 'A'] == _max) sz += M;
         else sz += N;
      printf("Case %d: %d\n", t, sz);
   }
   return(0);
}
