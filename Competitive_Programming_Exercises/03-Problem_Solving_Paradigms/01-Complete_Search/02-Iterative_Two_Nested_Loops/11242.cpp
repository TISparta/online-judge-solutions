#include <bits/stdc++.h>

using namespace std;

int n, m;
vector <int> v, w;
float _max;
vector <float> x;

int main(){
   while(scanf("%d %d", &n, &m) == 2){
      v.resize(n), w.resize(m), _max = 0, x.clear();
      for(int i = 0; i < n; i++) scanf("%d", &v[i]);
      for(int i = 0; i < m; i++) scanf("%d", &w[i]);
      for(int i = 0; i < n; i++)
         for(int j = 0; j < m; j++)
            x.push_back( (float)w[j] / v[i] );
      sort(x.begin(), x.end());
      for(int i = 0; i < x.size() - 1; i++)
         _max = max(_max, x[i+1] / x[i]);
      printf("%.2f\n", _max);
   }
   return(0);
}
