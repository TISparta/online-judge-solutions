#include <bits/stdc++.h>

using namespace std;

struct Team{
   string name;
   int b, c, d, e, f, g, h, i;
} tmp;

int tc, n, g, goals1, goals2, pos1, pos2;
string tournament_name, line, team1, team2, xx, yy;
vector <Team> v;

int findTeam(string x){
   for(int i = 0;i < v.size(); i++) if(v[i].name == x) return i;
}

bool cmp(Team x,Team y){
   if(x.b != y.b) return (x.b > y.b);
   if(x.d != y.d) return (x.d > y.d);
   if(x.g != y.g) return (x.g > y.g);
   if(x.h != y.h) return (x.h > y.h);
   if(x.c != y.c) return (x.c < y.c);
   xx = x.name, yy = y.name;
   transform(xx.begin(), xx.end(), xx.begin(), ::tolower);
   transform(yy.begin(), yy.end(), yy.begin(), ::tolower);
   return (xx < yy);
}

void printResults(){
   cout << tournament_name << endl;
   for(int i = 0; i < v.size(); i++)
      printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n", i + 1, v[i].name.c_str(), v[i].b, v[i].c, v[i].d, v[i].e, v[i].f, v[i].g, v[i].h, v[i].i);
}

int main(){
   scanf("%d\n", &tc);
   while(tc--){
      v.clear();
      getline(cin, tournament_name);
      scanf("%d\n", &n);
      for(int i = 0;i < n; i++){
         getline(cin, line);
         tmp.name = line;
         v.push_back(tmp);
      }
      scanf("%d\n", &g);
      while(g--){
         getline(cin, line);
         team1 = line.substr(0, line.find("#"));
         line.replace(0, line.find("#") + 1, "");
         goals1 = stoi(line.substr(0, line.find("@")));
         line.replace(0, line.find("@") + 1, "");
         goals2 = stoi(line.substr(0, line.find("#")));
         line.replace(0, line.find("#") + 1, "");
         team2 = line;
         pos1 = findTeam(team1);
         pos2 = findTeam(team2); 
         v[pos1].c += 1, v[pos2].c += 1;
         if(goals1 > goals2) v[pos1].d += 1, v[pos2].f += 1, v[pos1].b += 3;
         else if(goals1 < goals2) v[pos1].f += 1, v[pos2].d += 1, v[pos2].b += 3;
         else v[pos1].e += 1, v[pos2].e += 1, v[pos1].b += 1, v[pos2].b += 1;
         v[pos1].h += goals1, v[pos1].i += goals2;
         v[pos2].h += goals2, v[pos2].i += goals1;
         v[pos1].g = v[pos1].h-v[pos1].i;
         v[pos2].g = v[pos2].h-v[pos2].i;
      }
      sort(v.begin(), v.end(), cmp);
      printResults();
      if(tc) putchar('\n');
   }
   return(0);
}
