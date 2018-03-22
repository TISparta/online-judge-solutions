#include <bits/stdc++.h>

#define SIZE 110

using namespace std;

int tc, W, H, n, a, b, L[SIZE][SIZE], R[SIZE][SIZE], D[SIZE][SIZE], U[SIZE][SIZE];
bool grid[SIZE][SIZE];
vector <int> v1, v2;

void Probability(vector <int>& v){
   memset(L, 0, sizeof L), memset(R, 0, sizeof R);
   memset(D, 0, sizeof D), memset(U, 0, sizeof U);
   for(int x = 0; x < W; x++)
      for(int y = 0, ac = 0; y < H; y++)
         ac = ac * grid[x][y] + grid[x][y], L[x][y] = ac;
   for(int x = 0; x < W; x++)
      for(int y = H - 1, ac = 0; y >= 0; y--)
         ac = ac * grid[x][y] + grid[x][y], R[x][y] = ac;
   for(int y = 0; y < H; y++)
      for(int x = 0, ac = 0; x < W; x++)
         ac = ac * grid[x][y] + grid[x][y], U[x][y] = ac;
   for(int y = 0; y < H; y++)
      for(int x = W - 1, ac = 0; x >= 0; x--)
         ac = ac * grid[x][y] + grid[x][y], D[x][y] = ac;
   for(int x = 0; x < W; x++)
      for(int y = 0; y < H; y++)
         if( grid[x][y] )
            v.push_back( L[x][y] + R[x][y] + U[x][y] + D[x][y] );
}

int main(){
   scanf("%d", &tc);
   while(tc--){
      scanf("%d %d %d", &W, &H, &n);
      memset(grid, false, sizeof grid);
      for(int it = 0; it < n; it++){
         scanf("%d %d", &a, &b);
         grid[a][b] = true;
      }
      Probability(v1);
      memset(grid, false, sizeof grid);
      for(int it = 0; it < n; it++){
         scanf("%d %d", &a, &b);
         grid[a][b] = true;
      }
      Probability(v2);
      sort(v1.begin(), v1.end());
      sort(v2.begin(), v2.end());
      puts( v1 == v2 ? "YES" : "NO" );
      v1.clear(), v2.clear();
   }
   return(0);
}
