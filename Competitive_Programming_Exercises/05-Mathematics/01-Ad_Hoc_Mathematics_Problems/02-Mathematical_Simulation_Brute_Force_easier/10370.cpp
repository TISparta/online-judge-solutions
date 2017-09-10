#include <bits/stdc++.h>

using namespace std;

int main(){
   int c, n, tmp, ct;
   float mean;
   vector <int> a;
   scanf("%d", &c);
   while(c--){
      mean = 0;
      ct = 0;
      a.clear();
      scanf("%d", &n);
      for(int i = 0; i < n; i++)
         scanf("%d", &tmp), mean += tmp, a.push_back(tmp);
         mean /= n;
      for(int i = 0; i < n; i++)
         if(a[i] > mean)
            ct++;
      printf("%.3f%%\n", (float)ct / n * 100);
         
   }
   return(0);
}
