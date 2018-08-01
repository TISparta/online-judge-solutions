#include <bits/stdc++.h>

#define MAX_X 1010
#define INF (int)1e8

using namespace std;

int tc,X,v[15][MAX_X],memo[15][MAX_X];

int dp(int x,int y){
	if(x<0 || x>9) return INF;
	if(y==X && x==0) return 0;
	if(y==X && x!=0) return INF;
	if(~memo[x][y]) return memo[x][y];
	return memo[x][y] = min(60-v[x][y]+dp(x+1,y+1),min(30-v[x][y]+dp(x,y+1),20-v[x][y]+dp(x-1,y+1)));
}

int main(){
	scanf("%d",&tc);
	while(tc--){
		memset(memo,-1,sizeof memo);
		scanf("%d",&X);
		X /= 100;
		for(int i=9;i>=0;i--)
			for(int j=0;j<X;j++) scanf("%d",&v[i][j]);
		printf("%d\n\n",dp(0,0));
	}
	return(0);
}
