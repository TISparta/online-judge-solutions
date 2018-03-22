#include <bits/stdc++.h>

using namespace std;

int n, m, tmp;
vector < pair<int, int> > v;

bool cmp( pair <int, int> x, pair <int, int> y){
   if(x.first != y.first) return (x.first < y.first);
   if((x.second & 1) && !(y.second & 1)) return true;
   if(!(x.second & 1) && (y.second & 1)) return false;
   if((x.second & 1) && (y.second & 1)) return (x.second > y.second);
   if(!(x.second & 1) && !(y.second & 1)) return (x.second < y.second);
}

int main(){
   while(scanf("%d %d", &n, &m),n | m){
      v.resize(n);
      for(int i = 0; i < n; i++) scanf("%d", &tmp), v[i] = make_pair(tmp % m, tmp);
      sort(v.begin(), v.end(), cmp);
      printf("%d %d\n", n, m);
      for(int i = 0; i < n; i++)
         printf("%d\n", v[i].second);
   }
   puts("0 0");
   return(0);
}
