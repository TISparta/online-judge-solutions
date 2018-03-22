#include <bits/stdc++.h>

#define MAX 6

using namespace std;

double L[MAX], tmp;
int G[MAX], Y[MAX], R[MAX], tc, pib, N;
vector <int> v;

bool isGreen(double time, int p){
   tmp = fmod(time, R[p] + Y[p] + G[p]);
   if(tmp <= G[p] + Y[p]) return true;
   return false;
}

bool isValid(int vel){
   for(int i = 0; i < N; i++)
      if(!isGreen(3600 * L[i] / vel, i))
         return false;
   return true;
}

int main(){
   while(scanf("%d", &N), N != -1){
      v.clear();
      for(int i = 0; i < N; i++) scanf("%lf %d %d %d", &L[i], &G[i], &Y[i], &R[i]);
      for(int i = 30; i <= 60; i++)
         if(isValid(i)) v.push_back(i);
      printf("Case %d:", ++tc);
      for(int i = 0; i < v.size(); i++){
         printf(" %d", v[i]), pib = i;
         while(v[i + 1] - v[i] == 1) i++;
         if(i != pib) printf("-%d", v[i]);
         if(i != v.size() - 1) putchar(',');
      }
      if(!v.size()) printf(" No acceptable speeds.\n");
      else putchar('\n');
   }
   return(0);
}
