#include <bits/stdc++.h>

using namespace std;

vector < pair<long long, long long> > v;
int k, lim;
bool proof;

int main(){
   while(scanf("%d",&k) == 1){
      lim = 10000 * k;
      for(int y = k + 1; y < lim; y++)
         if((k * y) % (y - k)==0)
               v.push_back( make_pair(k * y/ (y - k), y)), lim = k * y / (y - k);
      sort(v.begin(), v.end());
      cout << v.size() << endl;
      for(int i = v.size() - 1; i >= 0; i--)
         printf("1/%d = 1/%lld + 1/%lld\n", k, v[i].first, v[i].second);
      v.clear();
   }     
}
