#include <bits/stdc++.h>

using namespace std;

int main(){
   int c, n, t = 0, ct;
   vector <int> a;
   scanf("%d", &c);
   while(c--){
      ct = 0;
      a.clear();
      scanf("%d", &n);
      for(int i = 2; ; i++){
         if(!(n % i))
            a.push_back(i), a.push_back(n / i), ct++;
         if(ct == 2)
            break;
      }
      printf("Case #%d: %d = %d * %d = %d * %d\n", ++t, n, a[0], a[1], a[2], a[3]);
   }
   return(0);
}
