#include <bits/stdc++.h>

using namespace std;

const int SIZE = 210, LEN = 210;

int n, k, m, v[SIZE];
char line[LEN], tmp[LEN];

int gcd(int a, int b){
   return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b){
   return a * ( b / gcd(a, b) );
}

void GetCycle(){
   m = 1;
   for(int it = 0; it < n; it++){
      int ct = 1, a = v[it];
      while(a != it) a = v[a], ct++;
      m = lcm(m, ct);
   }
}

int main(){
   while(scanf("%d", &n), n){
      for(int it = 0; it < n; it++) scanf("%d", v + it), v[it]--;
      GetCycle();
      while(scanf("%d", &k), k){
         getchar();
         memset(line, ' ', sizeof line);
         cin.getline(line, LEN);
         line[strlen(line)] = ' ';
         line[n] = '\0';
         k %= m;
         while(k--){
            memset(tmp, ' ', sizeof tmp);
            tmp[n] = '\0';
            for(int it = 0; it < n; it++)
               tmp[v[it]] = line[it];
            strcpy(line, tmp);
         }
         printf("%s\n", line);
      }
      putchar('\n');
   }
   return(0);
}
