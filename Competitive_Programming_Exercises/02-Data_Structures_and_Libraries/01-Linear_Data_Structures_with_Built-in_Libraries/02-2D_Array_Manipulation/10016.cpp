#include <bits/stdc++.h>

#define SIZE 110

using namespace std;

int tc, n, t, option, v[SIZE][SIZE], aux[SIZE][SIZE], pib, px, py, dt, tmp;

void complete(){
   for(int i = px; i <= py + dt; i++)
      v[i][py] = aux[i][py], v[i][py + dt] = aux[i][py + dt]; 
   for(int j = py; j <= py + dt; j++)
      v[px][j] = aux[px][j], v[px + dt][j] = aux[px + dt][j];
}

void transform1(int a, int b, int c, int d){
   for(int i = px; i <= px + dt; i++)
      aux[i][py] = v[a * i + b][c * py + d], aux[i][py + dt] = v[a * i + b][c * (py + dt) + d];
   for(int j = py; j <= py + dt; j++)
      aux[px][j] = v[a * px + b][c * j + d], aux[px + dt][j] = v[a * (px + dt) + b][c * j + d];
}

void transform2(int a,int b,int c,int d){
   for(int i = px; i <= px + dt; i++)
      aux[i][py] = v[a * py + b][c * i + d], aux[i][py + dt] = v[a * (py + dt) + b][c * i + d];
   for(int j = py; j <= py + dt; j++)
      aux[px][j] = v[a * j + b][c * px + d], aux[px + dt][j] = v[a * j + b][c * (px + dt) + d];
}

void Upside_Down(int r){
   px = py = tmp-r;
   dt = (r<<1) + pib;
   transform1(-1, n + 1, 1, 0);
   complete();
}

void Left_Right(int r){
   px = py = tmp-r;
   dt = (r<<1) + pib;
   transform1(1, 0, -1, n + 1);
   complete();
}

void Main_Diagonal(int r){
   px = py = tmp-r;
   dt = (r<<1) + pib;
   transform2(1, 0, 1, 0);
   complete();
}

void Main_Inverse_Diagonal(int r){
   px = py = tmp-r;
   dt = (r<<1) + pib;
   transform2(-1, n + 1, -1, n + 1);
   complete();

}

void printMatrix(){
   for(int i = 1; i <= n; i++)
      for(int j = 1;j <= n; j++)
         printf( j != n ? "%d " : "%d\n", v[i][j]);
}

int main(){
   scanf("%d", &tc);
   while(tc--){
      scanf("%d", &n);
      pib = (n&1) ? 0 : 1;
      tmp = (n+1) >> 1;
      for(int i = 1; i <= n; i++)
         for(int j = 1; j <= n; j++) scanf("%d", &v[i][j]);
      for(int ring = tmp - 1; ring >= 0; ring--){
         scanf("%d", &t);
         while(t--){
            scanf("%d", &option);
            if(option == 1) Upside_Down(ring);
            else if(option == 2) Left_Right(ring);
            else if(option == 3) Main_Diagonal(ring);
            else Main_Inverse_Diagonal(ring);
         } 
      }
      printMatrix();
   }
   return(0);
}
