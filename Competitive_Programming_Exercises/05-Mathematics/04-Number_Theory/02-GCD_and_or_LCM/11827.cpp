#include <bits/stdc++.h>

#define SIZE 110
#define LIM 1010

using namespace std;


int tc, v[SIZE], ct, ans;
char line[LIM], *p;

int gcd(int a,int b){
   return b == 0 ? a : gcd(b, a % b);
}

int main(){
   scanf("%d\n", &tc);
   while(tc--){
      ct = 0;
      cin.getline(line, LIM);
      p = strtok(line, " ");
      while(p){
         v[ct++] = atoi(p);
         p = strtok(NULL, " ");
      }
      ans = -1;
      for(int it1 = 0; it1 < ct; it1++)
         for(int it2 = it1 + 1; it2 < ct; it2++)
            ans = max(ans, gcd(v[it1], v[it2]));
      printf("%d\n", ans);
   }
   return(0);
}
