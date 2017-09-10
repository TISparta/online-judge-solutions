#include <bits/stdc++.h>

using namespace std;

const int SIZE = 210, LEN = 10000, INF = 1000000000;

typedef pair <int, int> ii;

int tc, a, b, V, start_, end_;
char line[LEN], *p;
double W[SIZE][SIZE], dis[SIZE];
ii S, T, vert[SIZE];

int Dijkstra(int source, int target){
   fill(dis, dis + V, INF);
   dis[source] = 0.0;
   set < pair<double, int> > st;
   st.insert( make_pair(0.0, source) );
   while( not st.empty() ){
      int u = st.begin() -> second;
      st.erase( st.begin() );
      for(int v = 0; v < V; v++){
         if( dis[v] > dis[u] + W[u][v] ){
            dis[v] = dis[u] + W[u][v];
            st.insert( make_pair(dis[v], v) );
         }
      }
   }
   return round(dis[target] + 1e-6);
}

int main(){
   scanf("%d\n", &tc);
   while(tc--){
      V = 0;
      fill(W[0], W[SIZE], INF);
      cin.getline(line, LEN);
      sscanf(line, "%d %d %d %d", &S.first, &S.second, &T.first, &T.second);
      vert[V++] = S, vert[V++] = T;
      while(cin.getline(line, LEN), strlen(line)){
         p = strtok(line, " ");
         start_ = V;
         while(p){
            a = atoi(p);
            p = strtok(NULL, " ");
            b = atoi(p);
            p = strtok(NULL, " ");
            if( a == -1 and b == -1 ) break;
            vert[V++] = ii(a, b);
         }
         end_ = V;
         for(int i = start_ + 1; i < end_; i++)
               W[i][i - 1] = W[i - 1][i] = hypot(vert[i].first - vert[i - 1].first, vert[i].second - vert[i - 1].second) * 3.0 / 2000.0;
      }
      for(int i = 0; i < V; i++)
         for(int j = 0; j < V; j++)
            W[j][i] = W[i][j] = min(W[i][j], hypot(vert[i].first - vert[j].first, vert[i].second - vert[j].second) * 3.0 / 500.0);
      printf("%d\n", Dijkstra(0, 1));
      if( tc ) putchar('\n');
   }
   return(0);
}
