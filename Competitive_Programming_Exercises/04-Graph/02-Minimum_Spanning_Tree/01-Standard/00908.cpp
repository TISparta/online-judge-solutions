#include <bits/stdc++.h>

using namespace std;

struct UnionFind{
   vector <int> path, rank, setSize;

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

int tc, N, K, M, s, a, b, w, original_cost;
vector < pair < int, ii > > EdgeList;

int Kruskal(){
   UnionFind UF(N);
   int new_cost = 0, setSize = 1;
   sort(EdgeList.begin(), EdgeList.end());
   for(int it = 0; it < M + K; it++){
      pair <int, ii> front = EdgeList[it];
      if( not UF.isSameSet(front.second.first, front.second.second) )
         new_cost += front.first, setSize++;
         UF.unionSet(front.second.first, front.second.second);
      if( setSize == N ) break;
   }
   return new_cost;
}

int main(){
   while(~scanf("%d", &N)){
      if(tc++) putchar('\n');
      original_cost = 0;
      EdgeList.clear();
      for(int it = 0; it + 1 < N; it++){
         scanf("%*d %*d %d", &s);
         original_cost += s;
      }
      scanf("%d", &K);
      for(int it = 0; it < K; it++){
         scanf("%d %d %d", &a, &b, &w);
         EdgeList.push_back( make_pair(w, ii(a, b) ) );
      }
      scanf("%d", &M);
      for(int it = 0; it < M; it++){
         scanf("%d %d %d", &a, &b, &w);
         EdgeList.push_back( make_pair(w, ii(a, b) ) );
      }
      printf("%d\n", original_cost);
      printf("%d\n", Kruskal());
   }
   return(0);
}
