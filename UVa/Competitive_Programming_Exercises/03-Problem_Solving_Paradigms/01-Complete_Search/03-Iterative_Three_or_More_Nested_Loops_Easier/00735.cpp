#include <bits/stdc++.h>

#define MAX 100000

using namespace std;

int n,numberOfCombinations, numberOfPermutations, t;
vector <int> ans[MAX], v, x;

inline void asterisks(){
   for(int i = 0; i < 70; i++) putchar('*');
   putchar('\n');
}

void addSolution(int num1, int num2, int num3){
   v.clear();
   v.push_back(num1), v.push_back(num2), v.push_back(num3);
   sort(v.begin(), v.end());
   for(int i = 0; i < numberOfCombinations; i++)
      if(ans[i] == v) return;
   ans[numberOfCombinations++] = v;
   if(num1 == num2 && num1 != num3) numberOfPermutations += 3;
   if(num1 != num2 && num1 == num3) numberOfPermutations += 3;
   if(num2 == num3 && num1 != num3) numberOfPermutations += 3;
   if(num1 != num2 && num2 != num3) numberOfPermutations += 6;
   if(num1 == num2 && num2 == num3) numberOfPermutations += 1;
}

void solve(){
   for(int a = 0; a < x.size(); a++)
      for(int b = 0;b < x.size(); b++)
         for(int c = 0;c < x.size(); c++)
            if(x[a] + x[b] + x[c] == n)
               addSolution(x[a], x[b], x[c]);
}

void reset(){
   for(int i = 0; i < numberOfCombinations; i++)
      ans[i].clear();
   numberOfCombinations = numberOfPermutations = 0;
}

void generate(){
   x.push_back(0);
   for(int i = 1; i <= 20; i++)
      x.push_back(i), x.push_back(i * 2), x.push_back(i * 3);
   x.push_back(50);
}

int main(){
   generate();
   while(scanf("%d", &n),n > 0){
      reset();
      solve();
      if(!numberOfCombinations)
         printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n", n);
      else{
         printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\n", n, numberOfCombinations);
         printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n", n, numberOfPermutations);
      }
      asterisks();
   }
   printf("END OF OUTPUT\n");
   return(0);
}
