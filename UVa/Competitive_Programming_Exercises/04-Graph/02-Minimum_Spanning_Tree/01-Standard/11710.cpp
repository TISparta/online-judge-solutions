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

const int LIM = 15;
int s, c, ct, w, cost;
char word1[LIM], word2[LIM];
vector < pair<int, ii> > EdgeList;
map < string, int > mp;

int Kruskal(){
   if( s == 1 ) return 0;
   UnionFind UF(s);
   sort(EdgeList.begin(), EdgeList.end());
   int min_cost = 0, setSize = 1;
   for(int it = 0; it < c; it++){
      pair <int, ii> front = EdgeList[it];
      if( not UF.isSameSet(front.second.first, front.second.second) )
         min_cost += front.first,
         UF.unionSet(front.second.first, front.second.second), setSize++;
      if( setSize == s ) return min_cost;
   }
   return -1;
}

int main(){
   while(scanf("%d %d\n", &s, &c), s | c){
      EdgeList.clear();
      mp.clear();
      ct = 0;
      for(int it = 0; it < s; it++){
         scanf("%s", word1);
         mp[word1] = ct++;
      }
      for(int it = 0; it < c; it++){
         scanf("%s %s %d\n", word1, word2, &w);
         EdgeList.push_back( make_pair(w, ii(mp[word1], mp[word2])  ));
      }
      scanf("%s", word1);
      cost = Kruskal();
      ( cost == -1 ) ? puts("Impossible") : printf("%d\n", cost);
   }
   return(0);
}
