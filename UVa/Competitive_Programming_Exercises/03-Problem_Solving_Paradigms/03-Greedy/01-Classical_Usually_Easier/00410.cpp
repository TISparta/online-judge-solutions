#include <bits/stdc++.h>

using namespace std;

int c, s, t, tc, pib, foo;
vector < pair <int, int> > v;
int ans[10][2];
double mean, imbalance;

int main(){
   while(scanf("%d %d", &c, &s) == 2){
      v.resize(s);
      mean = imbalance = t = 0;
      for(int i = 0; i < 10; i++)
         ans[i][0] = ans[i][1] = 0;
      for(int i = 0; i < s; i++){
         scanf("%d", &v[i].first), v[i].second = i;
         mean += v[i].first;
      }
      mean /= c;
      printf("Set #%d\n", ++tc);
      sort(v.begin(), v.end());
      pib = v.size() - 1;
      pib -= 2 * c - s;
      if(c <= s){
         for(int i = v.size() - 1; i > pib; i--)
            ans[v[i].second][0] = v[i].first;
      }
      else{
         for(int i = 0; i < s; i++)
            ans[v[i].second][0] = v[i].first;
      }
      for(int i = 0; i < pib; i++){
         foo = min(v[i].second, v[pib].second);
         ans[foo][0] = v[i].first;
         ans[foo][1] = v[pib].first;
         if(v[i].second > v[pib].second)
            swap(ans[foo][0], ans[foo][1]);
         pib--;
      }
      for(int i = 0; i < 10; i++){
         if(ans[i][0] && ans[i][1]){
            printf(" %d: %d %d\n", t++, ans[i][0], ans[i][1]);
            imbalance += abs(ans[i][0] + ans[i][1] - mean);
         }
         else if(ans[i][0] || ans[i][1]){
            printf(" %d: %d\n", t++, ans[i][0]);
            imbalance += abs(ans[i][0] - mean);
         }
      }
      for(int i = t; i < c; i++){
         printf(" %d:\n", i);
         imbalance += mean;
      }
      printf("IMBALANCE = %.5lf\n", imbalance);
      putchar('\n');
   }
   return(0);
}
