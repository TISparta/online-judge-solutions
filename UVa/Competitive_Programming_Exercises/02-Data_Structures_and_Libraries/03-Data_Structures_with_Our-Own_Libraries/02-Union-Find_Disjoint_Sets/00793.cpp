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

const int LIM = 20;
int tc, N, a, b, ans1, ans2;
char line[LIM], ch;

int main(){
   scanf("%d", &tc);
   while(tc--){
      scanf("%d\n", &N);
      ans1 = ans2 = 0;
      UnionFind UF(N);
      while(true){
         cin.getline(line, LIM);
         if( sscanf(line, "%c %d %d", &ch, &a, &b) == -1 ) break;
         if( ch == 'c' ) UF.unionSet(a - 1, b - 1);
         else{
            if( UF.isSameSet(a - 1, b - 1) ) ans1++;
            else ans2++;
         }
      }
      printf("%d,%d\n", ans1, ans2);
      if(tc) putchar('\n');
   }
   return(0);
}
