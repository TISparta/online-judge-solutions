#include <bits/stdc++.h>

using namespace std;

struct UnionFind{
   vector <int> path, rank;

   UnionFind(int N_){
      rank.assign(N_, 0);
      path.assign(N_, 0);
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
      int x = findSet(idx1), y = findSet(idx2);
      if( rank[x] > rank[y] ) path[y] = x;
      else path[x] = y;
      if( rank[x] == rank[y] ) rank[y]++;
   }
};

const int SIZE = 100010;

int a, b, ans;

int main(){
   while(~scanf("%d %d", &a, &b)){
      UnionFind UF(SIZE);
      ans = 0;
      if( not UF.isSameSet(a, b) )
         UF.unionSet(a, b);
      else
         ans++;
      while(scanf("%d", &a), a != -1){
         scanf("%d", &b);
         if( not UF.isSameSet(a, b) )
            UF.unionSet(a, b);
         else
            ans++;
      }
      printf("%d\n", ans);
   }
}
