#include <bits/stdc++.h>

using namespace std;

int main(){
   int n, q, m, u, v, l, r, mid, tmp;
   bool ok;
   scanf("%d", &n);
   vector <int> a;
   for(int i = 0; i < n; i++){
      ok = true;
      scanf("%d", &tmp);
      for(int j = 0; j < a.size(); j++)
         if(a[j] == tmp){
            ok = false;
            break;
         }
      if(ok)
         a.push_back(tmp);
   }
   scanf("%d", &q);
   while(q--){
      scanf("%d", &m);
      l = 0, r = 2 * a.size() - 2;
      while(r - l > 1){
         mid = (l + r) / 2;
         if(a[mid] < m)
            l = mid;
         else
            r = mid;
      }
      if(a[l] == m)
         l--;
      if(a[r] == m)
         r++;
      if(m > a[a.size() - 1])
         printf("%d ", a[a.size() - 1]);
      else if(l < 0 || m < a[0])
         printf("X ");
      else
         printf("%d ", a[l]);
      if(m < a[0])
         printf("%d\n", a[0]);
      else if(r >= a.size() || m > a[a.size() - 1])
         printf("X\n");
      else
         printf("%d\n", a[r]);
   }
   return(0);
}
