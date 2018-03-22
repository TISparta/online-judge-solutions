#include <bits/stdc++.h>

using namespace std;

int main(){
   string a;
   int d, lim;
   while(true){
      cin >> a;
      if(a.size() == 1 && a[0]=='0')
         break;
      if(a.size() & 1)
         d = sqrt(a[0] - '0'), lim = (a.size() - 1) / 2;
      else
         d = sqrt((a[0] - '0') * 10 + a[1] - '0'), lim = (a.size() - 2) / 2;
      printf("%d", d);
      for(int i = 0; i < lim; i++)
         putchar('0');
      putchar('\n');
   }
   return(0);
}
