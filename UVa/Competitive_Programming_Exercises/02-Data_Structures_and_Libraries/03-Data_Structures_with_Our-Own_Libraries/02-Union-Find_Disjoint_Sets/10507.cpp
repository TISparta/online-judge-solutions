#include <bits/stdc++.h>

using namespace std;

const int SIZE = 30;
int N, M, ans, idx, ct[SIZE];
char ch1, ch2, ch3;
bool vis[SIZE], wake_up;
vector <int> G[SIZE];
map <char, int> mp;

void clear_(){
   for(int it = 0; it < N; it++) G[it].clear();
   idx = ans = 0;
   memset(vis, false, sizeof vis);
   mp.clear();
   wake_up = false;
}

int main(){
   while(~scanf("%d", &N)){
      clear_();
      scanf("%d\n", &M);
      scanf("%c%c%c\n", &ch1, &ch2, &ch3);
      vis[0] = vis[1] = vis[2] = true;
      mp[ch3] = idx++;
      if( mp[ch2] == 0 and ch2 != ch3) mp[ch2] = idx++;
      if( mp[ch1] == 0 and ch1 != ch3) mp[ch1] = idx++;
      for(int it = 0; it < M; it++){
         scanf("%c%c\n", &ch1, &ch2);
         if( mp[ch1] == 0 and ch1 != ch3) mp[ch1] = idx++;
         if( mp[ch2] == 0 and ch2 != ch3) mp[ch2] = idx++;
         G[mp[ch1]].push_back(mp[ch2]);
         G[mp[ch2]].push_back(mp[ch1]);
      }
      while(true){
         if(all_of(vis, vis + N, [](int id){ return id; })){
            wake_up = true;
            break;
         }
         ans++;
         memset(ct, 0, sizeof ct);
         for(int it = 0; it < N; it++){
            if( vis[it] ) continue;
            for(int u = 0; u < G[it].size(); u++)
               if( vis[G[it][u]] )
                  ct[it]++;
         }
         bool possible = false;
         for(int it = 0; it < N; it++){
            if( ct[it] >= 3 )
               possible = true, vis[it] = true;
         }
         if( not possible ) break;
      }
      if( wake_up ) printf("WAKE UP IN, %d, YEARS\n", ans);
      else puts("THIS BRAIN NEVER WAKES UP");
   }
   return(0);
}
