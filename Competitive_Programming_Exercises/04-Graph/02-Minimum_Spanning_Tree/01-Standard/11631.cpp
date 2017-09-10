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

typedef pair <int, int> ii;

int n, m, x, y, w, total_cost;
vector < pair < int, ii > > EdgeList;

int Kruskal(){
   sort(EdgeList.begin(), EdgeList.end());
   UnionFind UF(n);
   int min_cost = 0, setSize = 1;
   for(int it = 0; it < m; it++){
      pair <int, ii > front = EdgeList[it];
      if( not UF.isSameSet(front.second.first, front.second.second) )
         min_cost += front.first, setSize++;
         UF.unionSet(front.second.first, front.second.second);
      if( setSize == n ) break;
   }
   return min_cost;
}

int main(){
   while(scanf("%d %d", &n, &m), n | m){
      EdgeList.clear();
      total_cost = 0;
      for(int it = 0; it < m; it++){
         scanf("%d %d %d", &x, &y, &w);
         EdgeList.push_back( make_pair( w, ii(x, y) ));
         total_cost += w;
      }
      printf("%d\n", total_cost - Kruskal());
   }
   return(0);
}
