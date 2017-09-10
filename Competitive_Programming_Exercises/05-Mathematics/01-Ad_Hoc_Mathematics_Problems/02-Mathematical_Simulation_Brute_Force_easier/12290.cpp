#include <bits/stdc++.h>

using namespace std;

int n, m, k, ct, t, s, pib;
bool v[500000];

bool seven(int num){
   while(num){
      if(num % 10 == 7)
         return true;   
      num /= 10;
   }
   return false;
}

int main(){
   for(int i = 0; i < 500000; i++)
      if(!(i % 7) || seven(i))
         v[i] = true;
   while(scanf("%d %d %d", &n, &m, &k), n | m | k){
      ct = t = 1, s = 0;
      while(true){
         if(ct == m && v[t])
            s++;
         if(s == k){
            printf("%d\n", t);
            break;
         }
         if(ct == n)
            pib = -1;
         else if(ct == 1)
            pib = 1;
         t++;
         ct += pib;
      }
   }
   return(0);
}
