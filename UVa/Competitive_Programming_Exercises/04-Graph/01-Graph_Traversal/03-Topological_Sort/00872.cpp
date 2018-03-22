#include <bits/stdc++.h>

using namespace std;

const int MAX_V = 50;

int tc;
string line, blank, x, y, z;
stringstream ss;
vector <string> v;
vector <int> ans;
map <string, int> mp;
bool pos[MAX_V][MAX_V], vis[MAX_V], found;

bool check(int id){
   for(int i = 0; i < ans.size(); i++)
      if( not pos[ans[i]][id] ) return false;
   return true;
}

void backtrack(){
   if( ans.size() == v.size() ){   
      for(int i = 0; i < ans.size(); i++){
         i == 0 ? cout << "" : cout << " ";
         cout << v[ans[i]];
      }
      cout << endl;
      found = true;
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
   backtrack();
   if( not found ) puts("NO");
   if( tc ) puts("");
}

void read(){
   memset(pos, true, sizeof pos);
   getline(cin, blank);
   getline(cin, line);
   ss.clear();
   ss << line;
   while( ss >> x ) v.push_back(x);
   sort(v.begin(), v.end());
   for(int i = 0; i < v.size(); i++) mp[v[i]] = i;
   getline(cin, line);
   ss.clear();
   ss << line;
   while( ss >> z){
      x = z.substr(0, z.find("<"));
      y = z.substr(z.find("<") + 1);
      int u = mp[x], v = mp[y];
      pos[v][u] = false;
   }
}

void clear(){
   v.clear();
   mp.clear();
   found = false;
}

int main(){
   cin >> tc;
   cin.ignore();
   while(tc--){
      read();
      solve();
      clear();
   }
   return(0);
}
