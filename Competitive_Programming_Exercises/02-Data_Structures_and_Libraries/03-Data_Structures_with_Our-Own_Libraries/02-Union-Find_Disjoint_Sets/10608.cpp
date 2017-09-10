#include <bits/stdc++.h>

using namespace std;

struct UnionFind{
   int numSets, largestSet;
   vector <int> path, rank, setSize;

   UnionFind(int N_): numSets(N_), largestSet(1){
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
      largestSet = max(largestSet, (int)max(setSize[x], setSize[y]));
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
      while(m--){
         scanf("%d %d", &a, &b);
         UF.unionSet(a - 1, b - 1);
      }
      printf("%d\n", UF.largestSet);
   }
   return(0);
}
