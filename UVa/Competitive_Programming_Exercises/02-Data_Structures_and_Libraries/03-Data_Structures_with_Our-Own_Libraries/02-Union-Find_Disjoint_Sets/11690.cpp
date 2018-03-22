#include <bits/stdc++.h>

using namespace std;

struct UnionFind{
   int numSets;
   vector <int> path, rank, setSize, w;

   UnionFind(int N_): numSets(N_){
      rank.assign(N_, 0);
      path.assign(N_, 0);
      setSize.assign(N_, 1);
      w.assign(N_, 0);
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
      if( rank[x] > rank[y] ) path[y] = x, w[x] += w[y], w[y] = 0;
      else path[x] = y, w[y] += w[x], w[x] = 0;
      if( rank[x] == rank[y] ) rank[y]++;
   }

   int sizeOfSet(int idx){
      return setSize[ findSet(idx) ];
   }
};

int tc, n, m, a, b;

int main(){
   scanf("%d", &tc);
   while(tc--){
      scanf("%d %d", &n, &m);
      UnionFind UF(n);
      for(int it = 0; it < n; it++){
         scanf("%d", &a);
         UF.w[it] = a;
      }
      while(m--){
         scanf("%d %d", &a, &b);
         UF.unionSet(a, b);
      }
      puts( all_of(UF.w.begin(), UF.w.end(), [](int it){ return ( it == 0 ); } ) ? "POSSIBLE" : "IMPOSSIBLE" );
   }
   return(0);
}
