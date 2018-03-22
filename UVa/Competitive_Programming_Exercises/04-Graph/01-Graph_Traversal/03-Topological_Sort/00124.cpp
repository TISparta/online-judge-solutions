#include <bits/stdc++.h>

using namespace std;

const int MAX_V = 50;

string line, x, y;
stringstream ss;
vector <string> v;
vector <int> ans;
map <string, int> mp;
bool pos[MAX_V][MAX_V], vis[MAX_V], first = true;

bool check(int id){
   for(int i = 0; i < ans.size(); i++)
      if( not pos[ans[i]][id] ) return false;
   return true;
}

void backtrack(){
   if( ans.size() == v.size() ){   
      for(int i = 0; i < ans.size(); i++) cout << v[ans[i]]; cout << endl;
      return;
   }
   for(int i = 0; i < v.size(); i++)
      if( not vis[i] and check(i) ){
         vis[i] = true;
         ans.push_back(i);
         backtrack();
         vis[i] = false;
         ans.pop_back();
      }
}

void solve(){
   if( not first ) puts("");
   first = false;
   backtrack();
}

void read(){
   memset(pos, true, sizeof pos);
   ss.clear();
   ss << line;
   while( ss >> x ) v.push_back(x);
   sort(v.begin(), v.end());
   for(int i = 0; i < v.size(); i++) mp[v[i]] = i;
   getline(cin, line);
   ss.clear();
   ss << line;
   while( ss >> x >> y){
      int u = mp[x], v = mp[y];
      pos[v][u] = false;
   }
}

void clear(){
   v.clear();
   mp.clear();
}

int main(){
   while(getline(cin, line)){
      read();
      solve();
      clear();
   }
   return(0);
}
