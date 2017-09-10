#include <bits/stdc++.h>

using namespace std;

struct UnionFind{
   int numSets;
   vector <int> path, rank, setSize;

   UnionFind(int N_): numSets(N_){
      rank.assign(N_, 0);
      path.assign(N_, 0);
      setSize.assign(N_, 1);
      for(int it = 0; it < N_; it++) path[it] = it;
   };

   int findSet(int idx){
      return ( path[idx] == idx ? idx : path[idx] = findSet(path[idx]) );
   }

   bool isSameSet(int idx1, int idx2){
      return ( findSet(idx1) == findSet(idx2) );
   }

   void unionSet(int idx1, int idx2){
      if( isSameSet(idx1, idx2) ) return;
      numSets--;
      int x = findSet(idx1), y = findSet(idx2);
      if( rank[x] > rank[y] ) path[y] = x, setSize[x] += setSize[y];
      else path[x] = y, setSize[y] += setSize[x];
      if( rank[x] == rank[y] ) rank[y]++;
   }

   int sizeOfSet(int idx){
      return setSize[ findSet(idx) ];
   }
};

const int LIM = 25;
int tc, F, ct, idx1, idx2;
char s1[LIM], s2[LIM];
map < string, int > mp;

int main(){
   scanf("%d", &tc);
   while(tc--){
      scanf("%d\n", &F);
      mp.clear(), ct = 0;
      UnionFind UF(F + 1);
      for(int it = 0; it < F; it++){
         scanf("%s %s", s1, s2);
         idx1 = mp[s1];
         if( mp[s1] == 0 ) mp[s1] = idx1 = ++ct;
         idx2 = mp[s2];
         if( mp[s2] == 0 ) mp[s2] = idx2 = ++ct;
         UF.unionSet(idx1, idx2);
         printf("%d\n", UF.sizeOfSet(idx1));
      }
   }
   return(0);
}
