#include <bits/stdc++.h>

#define SIZE 10010
#define MAX_K 110

using namespace std;

int tc,n,k,v[SIZE];
bool memo[SIZE][MAX_K],visited[SIZE][MAX_K];

bool dp(int pos,int current){
	current = ((current%k)+k)%k;
	if(pos==n) return (current==0);
	if(visited[pos][current]) return memo[pos][current];
	visited[pos][current] = true;
	if(memo[pos][current]==false)
		memo[pos][current] |= dp(pos+1,current+v[pos]);
	if(memo[pos][current]==false)
		memo[pos][current] |= dp(pos+1,current-v[pos]);
	return memo[pos][current];
}

int main(){
	scanf("%d",&tc);
	while(tc--){
		memset(visited,false,sizeof visited);
		memset(memo,false,sizeof memo);
		scanf("%d %d",&n,&k);
		for(int i=0;i<n;i++) scanf("%d",&v[i]);
		puts(dp(1,v[0]) ? "Divisible" : "Not divisible");
	}
	return(0);
}
