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

const int SIZE = 1010;

typedef pair <int, int> ii;

int tc, n, r, x[SIZE], y[SIZE], CC;
double roads, railroads;
vector < pair < int, ii > > EdgeList;

inline int pow2(int p){
   return p * p;
}

void Kruskal(){
   roads = railroads = 0, CC = 1;
   UnionFind UF(n);
   EdgeList.clear();
   for(int i = 0; i < n; i++)
      for(int j = i + 1; j < n; j++)
         EdgeList.push_back( make_pair( pow2(x[i] - x[j]) + pow2(y[i] - y[j]), ii(i, j) ) );
   sort(EdgeList.begin(), EdgeList.end());
   for(int it = 0; it < EdgeList.size(); it++){
      pair <int, ii> front = EdgeList[it];
      if( not UF.isSameSet(front.second.first, front.second.second) ){
         UF.unionSet(front.second.first, front.second.second);
         if( front.first <= r ) roads += sqrt(front.first);
         else railroads += sqrt(front.first), CC++;
      }
   }
}

int main(){
   scanf("%d", &tc);
   for(int t = 1; t <= tc; t++){
      scanf("%d %d", &n, &r), r *= r;
      for(int it = 0; it < n; it++) scanf("%d %d", x + it, y + it);
      Kruskal();
      printf("Case #%d: %d %d %d\n", t, CC, (int)round(roads), (int)round(railroads));
   }
   return(0);
}
