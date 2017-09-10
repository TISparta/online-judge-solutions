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

int n, c, x, y;

inline int e(int id){
   return id + n;
}

int main(){
   scanf("%d", &n);
   UnionFind UF(2 * n);
   while(scanf("%d %d %d",&c, &x, &y), c | x | y){
      if( c == 1 ){
         if( UF.isSameSet(x, e(y)) ) puts("-1");
         else UF.unionSet(x, y), UF.unionSet( e(x), e(y) );
      }
      else if( c == 2 ){
         if( UF.isSameSet(x, y) ) puts("-1");
         else UF.unionSet(x, e(y)), UF.unionSet( e(x), y);
      }
      else if( c == 3 ) printf("%d\n", UF.isSameSet(x, y));
      else printf("%d\n", UF.isSameSet(x, e(y)));
   }
   return(0);
}
