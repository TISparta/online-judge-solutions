#include <bits/stdc++.h>

using namespace std;

vector <tuple <int, int, int> > v[200000];
int tc, K;

int main(){
   for(int a = 0; a <= 225; a++)
      for(int b = a; b <= 225; b++)
         for(int c = b; c <= 225; c++)
            if(v[a * a + b * b + c * c].size() == 0)
               v[a * a + b * b + c * c].push_back(make_tuple(a, b, c));
   scanf("%d", &tc);
   while(tc--){
      scanf("%d", &K);
      if(v[K].size() == 0) puts("-1");
      else printf("%d %d %d\n", get<0>(v[K][0]), get<1>(v[K][0]), get<2>(v[K][0]));
   }
   return(0);
}
