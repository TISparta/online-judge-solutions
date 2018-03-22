#include <bits/stdc++.h>

#define SIZE 110
#define LEN 30

using namespace std;

int tc, N, ct;
char v[SIZE][LEN], dic[SIZE][LEN], s[LEN], ss[LEN], ans[SIZE][LEN];

int main(){
   scanf("%d", &tc);
   while(tc--){
      scanf("%d", &N);
      for(int it = 0; it < N; it++){
         scanf("%s", v[it]);
         strcpy(ss, v[it]);
         sort(ss, ss + strlen(ss));
         strcpy(dic[it], ss);
      }
      while(scanf("%s", s), strcmp(s, "END") != 0){
         ct = 0;
         strcpy(ss, s);
         sort(ss, ss + strlen(ss));
         for(int it = 0; it < N; it++)
            if( strcmp(dic[it], ss) == 0 )
               strcpy(ans[ct++], v[it]);
         printf("Anagrams for: %s\n", s);
         if( ct == 0 ) printf("No anagrams for: %s\n", s);
         for(int it = 0; it < ct; it++)
            printf("%3d) %s\n", it + 1, ans[it]);
      }
      if(tc) putchar('\n');
   }
   return(0);
}
