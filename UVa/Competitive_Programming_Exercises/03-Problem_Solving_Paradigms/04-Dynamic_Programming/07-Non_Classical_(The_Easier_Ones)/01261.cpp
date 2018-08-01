#include <bits/stdc++.h>

using namespace std;

int tc;
set<string>visited;
map<string,bool>memo;
string line;

bool dp(string s){
	if(s.empty()) return true;
	if(visited.find(s)!=visited.end()) return memo[s];
	int l,r,j;
	for(int i=0;i<s.size();){
		l = i;
		for(j=i;j<s.size();j++)
			if(s[j]==s[i]) r = j;
			else break;
		i = j;
		if(l!=r){
			string ss;
			for(int p=0;p<s.size();p++)
				if(!(l<=p && p<=r)) ss += s[p];
			memo[s] |= dp(ss);
			visited.insert(ss);
		}
	}
	return memo[s] |= false;
}

int main(){
	scanf("%d",&tc);
	while(tc--){
		cin>>line;
		printf("%d\n",dp(line));
	}
	return(0);
}
