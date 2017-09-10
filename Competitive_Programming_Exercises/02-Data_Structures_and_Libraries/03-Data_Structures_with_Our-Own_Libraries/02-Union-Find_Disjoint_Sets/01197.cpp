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

int n, m, k, a, b;

int main(){
   while(scanf("%d %d", &n, &m), n | m){
      UnionFind UF(n);
      while(m--){
         scanf("%d", &k);
         if(k) scanf("%d", &a);
         for(int it = 1; it < k; it++)
            scanf("%d", &b), UF.unionSet(a, b);
      }
      printf("%d\n", UF.sizeOfSet(0));
   }
}
