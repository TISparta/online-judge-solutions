#include <bits/stdc++.h>

using namespace std;

int p, n, ans1, ans2, largest;
vector <int> v;

int main(){
   while(scanf("%d\n%d", &p, &n) == 2){
      v.resize(n);
      largest = 0;
      for(int i = 0; i < n; i++)
         scanf("%d", &v[i]);
      for(int l = 0, r; l < n; l++){
         if(v[n - 1] - v[l] < p) r = n - 1;
         else r = lower_bound(v.begin(), v.end(), v[l] + p - 1) - v.begin();
         while(v[r] - v[l] >= p) r--;
         while(r + 1 < n && v[r + 1] == v[r]) r++;
         if(v[r] - v[l] < p && r - l + 1 > largest) largest = r - l + 1, ans1 = v[l], ans2 = v[r];
      }
      printf("%d %d %d\n", largest, ans1, ans2);
   }
   return(0);
}
