#include <bits/stdc++.h>

#define SIZE 1010

using namespace std;

int n, d, ans, tc, j, x, y;
pair <double, double> v[SIZE];
bool check;
double dx;

int main(){
   while(scanf("%d %d", &n, &d), n | d){
      check = true;
      for(int i = 0; i < n; i++){
         scanf("%d %d", &x, &y);
         if(y > d) check = false;
         dx = sqrt(d * d - y * y);
         v[i] = make_pair(x + dx, x - dx);
      }
      sort(v ,v + n);
      ans = 0;
      for(int i = 0; check && i < n; ans++){
         for(j = i; j <n && v[i].first >= v[j].second; j++) ;
         i = j;
      }
      ans = check ? ans : -1;
      printf("Case %d: %d\n", ++tc, ans);
   }
   return(0);
}
