#include <bits/stdc++.h>

using namespace std;

char s[50];
double n, l, r, ll, rr;
bool ok;

int main(){
   while(scanf("%s", s)){
      if(sscanf(s, "%lf", &n) == 0) break;
      ok = true;
      l = 0.0 , r = 1.0;
      for(int i = 0; i < 80; i++){
         ll = (2.0 * l + r) / 3.0, rr = (l + 2.0 * r) / 3.0;
         if(fabs(n - ll) < 1e-15) break;
         if(fabs(n - rr) < 1e-15) break;
         if(n < ll) r = ll;
         else if(n > rr) l = rr;
         else{
            ok = false;
            break;
         }
      }
      puts( ok ? "MEMBER" : "NON-MEMBER" );
   }
   return(0);
}
