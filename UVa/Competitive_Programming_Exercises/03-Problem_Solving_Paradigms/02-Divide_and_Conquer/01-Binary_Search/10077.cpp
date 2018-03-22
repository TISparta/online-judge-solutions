#include <bits/stdc++.h>

using namespace std;

int main(){
   int n, m, nn, mm, nl, ml, nr, mr;
   while(scanf("%d%d", &n, &m), n != 1 || m != 1){
      nl = 0, nr = 1;
      ml = 1, mr = 0;
      while(true){
         nn = nl + nr;
         mm = ml + mr;
         if(nn == n && mm == m)
            break;
         if(m * nn < n * mm){
            putchar('R');
            nl = nn;
            ml = mm;
         }
         else{
            putchar('L');
            nr = nn;
            mr = mm;
         }
      }
      putchar('\n');
   }
   return(0);
}
