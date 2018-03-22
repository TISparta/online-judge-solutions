#include <bits/stdc++.h>

using namespace std;

int t, ans, _max, ct[110];
char s[110][50], a1, a2, a3, a4, a5, b1, b2, b3, b4, b5;
vector < pair <char, char> > c[110];

void reset(){
   for(int i = 0; i < t; i++)
      c[i].clear(), ct[i]=0;
   t = _max = -1;
}

void solve(){
   for(int i = 0; i < t; i++)
      for(int j = 0; j < t; j++)
         for(int k = 0; k < 5; k++)
            for(int m = 0; m < 5; m++)
               if(c[i][k].first == c[j][m].first &&
                  c[i][k].second == c[j][m].second)
                  ct[i]++;
   for(int i = 0; i < t; i++)
      if(ct[i] > _max) _max = ct[i], ans = i + 1;
   printf("%d\n", ans);
   reset();
}

int main(){
   while(cin.getline(s[t], 100)){
      if(s[t][0] == 'e') solve();
      if(s[t][0] == '#') break;
      sscanf(s[t], "%c/%c,%c/%c,%c/%c,%c/%c,%c/%c", &a1, &b1, &a2, &b2, &a3, &b3, &a4, &b4, &a5, &b5);
      c[t].push_back( make_pair(a1, b1) );
      c[t].push_back( make_pair(a2, b2) );
      c[t].push_back( make_pair(a3, b3) );
      c[t].push_back( make_pair(a4, b4) );
      c[t].push_back( make_pair(a5, b5) );
      t++;
   }
   return(0);
}
