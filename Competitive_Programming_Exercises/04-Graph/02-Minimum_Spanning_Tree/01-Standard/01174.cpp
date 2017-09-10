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

const int LIM = 35;
int tc, N, M, w, ct;
char word1[LIM], word2[LIM];
vector < pair < int, ii > > EdgeList;
map < string, int > mp;

int Kruskal(){
   UnionFind UF(N);
   sort(EdgeList.begin(), EdgeList.end());
   int min_cost = 0, setSize = 1;
   for(int it = 0; it < M; it++){
      pair < int, ii > front = EdgeList[it];
      if( not UF.isSameSet(front.second.first, front.second.second) )
         min_cost += front.first, setSize++,
         UF.unionSet(front.second.first, front.second.second);
      if( setSize == N ) break;
   }
   return min_cost;
}

int main(){
   scanf("%d", &tc);
   while(tc--){
      EdgeList.clear();
      mp.clear();
      ct = 0;
      scanf("%d", &N);
      scanf("%d\n", &M);
      for(int it = 0; it < M; it++){
         scanf("%s %s %d\n", word1, word2, &w);
         if( mp.find(word1) == mp.end() ) mp[word1] = ct++;
         if( mp.find(word2) == mp.end() ) mp[word2] = ct++;
         EdgeList.push_back( make_pair( w, ii(mp[word1], mp[word2]) ) );
      }
      printf("%d\n", Kruskal());
      if(tc) putchar('\n');
   }
   return(0);
}
