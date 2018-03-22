#include <bits/stdc++.h>

using namespace std;

int i;
long long n, a, b;
bool ind;

int main(){
   while(scanf("%lld", &n), n){
      ind = true;
      a = b = i = 0;
      while(n){
         if( (n>>0) & 1 ){
            if(ind) a |= 1<<i;
            else b |= 1<<i;
            ind = !ind;
         }
         i++;
         n >>= 1;
      }
      cout<<a<<' '<<b<<endl;
   }
   return(0);
}
