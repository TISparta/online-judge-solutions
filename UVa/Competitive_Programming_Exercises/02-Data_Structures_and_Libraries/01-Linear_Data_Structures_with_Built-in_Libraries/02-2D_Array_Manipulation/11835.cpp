#include <bits/stdc++.h>

#define SIZE 110

using namespace std;

int G, P, S, K, result[SIZE][SIZE], score[SIZE], final_result[SIZE], _max;

int main(){
   while(scanf("%d %d",&G,&P),G|P){
      for(int i = 1; i <= G; i++)
         for(int j = 1; j <= P; j++) scanf("%d", &result[i][j]);
      scanf("%d", &S);
      while(S--){
         _max = -1;
         scanf("%d", &K);
         for(int i = 1; i <= K; i++) scanf("%d", &score[i]);
         for(int j = 1; j <= P; j++){
            final_result[j] = 0;
            for(int i = 1;i <= G; i++)
               if(result[i][j] <= K)
                  final_result[j] += score[result[i][j]];
            _max = max(_max, final_result[j]);
         }
         vector <int> ans;
         for(int i = 1; i <= P; i++)
            if(final_result[i] == _max)
               ans.push_back(i);
         for(int i = 0; i < ans.size(); i++)
            printf(i != ans.size() - 1 ? "%d " : "%d\n", ans[i]);
      }
   }
   return(0);
}
