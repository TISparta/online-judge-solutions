#include <bits/stdc++.h>

using namespace std;

int tc, a, b, at, df, _max_at, _max_df;
string s;
vector < tuple <string, int, int> > v(10);
vector <int> u(5), w;
bool used[10];

void proof(int i, int j, int k, int l, int m){
   memset(used, false, sizeof used), df = 0;
   at = get<1>(v[i]) + get<1>(v[j]) + get<1>(v[k]) + get<1>(v[l]) + get<1>(v[m]);
   used[i] = used[j] = used[k] = used[l] = used[m] = true;
   for(int i = 0; i < 10; i++)
      if(!used[i]) df += get<2>(v[i]);
   if(at > _max_at){
      _max_at = at, _max_df = df;
      u[0] = i, u[1] = j, u[2] = k, u[3] = l, u[4] = m;
      w.clear();
      for(int i = 0; i < 10; i++)
         if(!used[i]) w.push_back(i);
   }
   else if(at == _max_at && df > _max_df){
      _max_df = df;
      u[0] = i, u[1] = j, u[2] = k, u[3] = l, u[4] = m;
      w.clear();
      for(int i = 0; i < 10; i++)
         if(!used[i]) w.push_back(i);
   }
}

int main(){
   scanf("%d", &tc);
   for(int t = 1; t <= tc; t++){
      getchar(), _max_at = _max_df = -1;
      for(int i = 0; i < 10; i++) cin >> s >> a >> b, v[i] = make_tuple(s, a, b);
      sort(v.begin(), v.end());
      for(int a = 0; a < 6; a++)
         for(int b = a + 1; b < 7; b++)
            for(int c = b + 1; c < 8; c++)
               for(int d = c + 1; d < 9; d++)
                  for(int e = d + 1; e < 10; e++)
                     proof(a, b, c, d, e);
      printf("Case %d:\n",t);
      putchar('(');
      for(int i = 0; i < 5; i++)
         cout<< get<0>(v[u[i]]), printf(i!=4 ? ", " : ")\n");
      putchar('(');
      for(int i = 0; i < 5; i++)
         cout<< get<0>(v[w[i]]), printf(i!=4 ? ", " : ")\n");
   }
   return(0);
}
