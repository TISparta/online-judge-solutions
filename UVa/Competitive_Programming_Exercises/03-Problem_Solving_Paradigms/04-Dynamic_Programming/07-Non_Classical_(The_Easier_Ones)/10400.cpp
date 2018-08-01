#include <bits/stdc++.h>

#define MAX_N 110
#define SIZE 64010

typedef long long ll;

using namespace std;

const int lower = -32000, upper = 32000;
int tc,p,v[MAX_N],target;
bool visited[MAX_N][SIZE],memo[MAX_N][SIZE];
short take[MAX_N][SIZE];

void printPath(int pos,int current){
	if(pos==p){
		printf("%d=%d\n",v[pos-1],v[pos]);
		return;
	}

	if(take[pos][current]==1){
		printf("%d+",v[pos-1]);
		printPath(pos+1,current+v[pos]);
	}

	else if(take[pos][current]==2){
		printf("%d-",v[pos-1]);
		printPath(pos+1,current-v[pos]);
	}

	else if(take[pos][current]==3){
		printf("%d*",v[pos-1]);
		printPath(pos+1,current*v[pos]);
	}

	else{
		printf("%d/",v[pos-1]);
		printPath(pos+1,current/v[pos]);
	}
}

bool dp(int pos,int current){
	if(pos==p) return (current==v[p]);
	if(visited[pos][current]) return memo[pos][current];
	visited[pos][current] = true;

	if(current+v[pos]<upper && !memo[pos][current]){
		take[pos][current] = 1;
		memo[pos][current] |= dp(pos+1,current+v[pos]);
	}
	
	if(current-v[pos]>lower && !memo[pos][current]){
		take[pos][current] = 2;
		memo[pos][current] |= dp(pos+1,current-v[pos]);
	}

	if(lower<(ll)current*v[pos] && (ll)current*v[pos]<upper && !memo[pos][current]){
		take[pos][current] = 3;
		memo[pos][current] |= dp(pos+1,current*v[pos]);
	}
	
	if(v[pos]!=0 && current%v[pos]==0 && !memo[pos][current]){
		take[pos][current] = 4;
		memo[pos][current] |= dp(pos+1,current/v[pos]);
	}

	return memo[pos][current];
}

int main(){
	scanf("%d",&tc);
	while(tc--){
		memset(visited,false,sizeof memo);
		memset(memo,false,sizeof memo);
		scanf("%d",&p);
		for(int i=0;i<=p;i++) scanf("%d",&v[i]);
		if(dp(1,v[0])) printPath(1,v[0]);
		else puts("NO EXPRESSION");
	}
	return(0);
}
