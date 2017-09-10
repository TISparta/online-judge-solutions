#include <bits/stdc++.h>

#define MAX_N 26
#define MAX_P 26
#define SIZE 20

using namespace std;

struct Team{
   int problems, total_time, number;
}aux;

struct In{
   int _n, _mm, _s, _l;
}tmp;

int tc, n, h, mm, score[MAX_N][MAX_P], it, _max;
char l, s, line[SIZE];
vector <Team> v;
vector <In> u;
bool solved[MAX_N][MAX_P];

void fillData(){
   for(int i = 0;i < u.size(); i++){
      if(solved[u[i]._n][u[i]._l] == false){
         if(u[i]._s == 1)
            solved[u[i]._n][u[i]._l] = true, score[u[i]._n][u[i]._l] += u[i]._mm;
         else
            score[u[i]._n][u[i]._l] += 20;
      }
   }
}

void fillScores(){
   for(int i = 1;i <= _max; i++){
      aux.number = i;      
      int sum = 0,np = 0;
      for(int j = 0;j < MAX_P; j++)
         if(solved[i][j]) sum += score[i][j], np++;
      aux.total_time = sum;
      aux.problems = np;
      v.push_back(aux);
   }
}

bool cmp1(In x, In y){
   if(x._mm != y._mm) return(x._mm < y._mm);
   return (x._s < y._s);
}

bool cmp2(Team x, Team y){
   if(x.problems != y.problems) return (x.problems > y.problems);
   if(x.total_time != y.total_time) return (x.total_time < y.total_time);
   return (x.number < y.number);
}

inline bool equals(Team x, Team y){
   return (x.problems == y.problems && x.total_time == y.total_time);
}

void printResults(){
   puts("RANK TEAM PRO/SOLVED TIME");
   for(int i = 0; i < v.size(); i++){
      if(i == 0 || !equals(v[i], v[i - 1])) it = i + 1;
      if(v[i].problems) printf("%4d %4d %4d       %4d\n", it, v[i].number, v[i].problems, v[i].total_time);
      else printf("%4d %4d\n", it, v[i].number);
   }
   v.clear(), u.clear();
   memset(score, 0, sizeof score);
   memset(solved, false, sizeof solved); 
}

int main(){
   scanf("%d\n", &tc);
   while(tc--){
      _max = -1;
      while(cin.getline(line, SIZE)){
         if(sscanf(line,"%d %c %d:%d %c", &n, &l, &h, &mm, &s) == -1) break;
         _max = max(_max, n);
         tmp._n = n, tmp._l = l - 'A', tmp._mm = h * 60 + mm;
         tmp._s = (s == 'Y') ? 1 : 0;
         u.push_back(tmp);
      }
      sort(u.begin(), u.end(), cmp1);
      fillData();
      fillScores();
      sort(v.begin(), v.end(), cmp2);
      printResults();      
      if(tc) putchar('\n');
   }
   return(0);
}
