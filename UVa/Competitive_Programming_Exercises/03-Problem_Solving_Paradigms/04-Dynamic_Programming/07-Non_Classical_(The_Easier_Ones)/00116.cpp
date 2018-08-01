#include <bits/stdc++.h>

#define MAX_M 15
#define MAX_N 110
#define INF (int)1e9

using namespace std;

int m,n,v[MAX_M][MAX_N],memo[MAX_M][MAX_N],take[MAX_M][MAX_N],ans,it;

int dp(int x,int y){
	if(y==n) return 0;
	if(memo[x][y]!=INF) return memo[x][y];
	int aux = INF;
	for(int row=-1;row<=1;row++){
		int r = (x+row+m)%m;
		int tmp = v[x][y]+dp(r,y+1);
		if(tmp<aux || (tmp==aux && r<take[x][y])) aux = tmp, take[x][y] = r;
	}
	return memo[x][y] = aux;
}

int main(){
	while(scanf("%d %d",&m,&n)==2){
		fill(memo[0],memo[0]+MAX_M*MAX_N,INF);
		ans = INF;
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++) scanf("%d",&v[i][j]);
		for(int i=0;i<m;i++){
			int pib = dp(i,0);
			if(pib<ans) ans = pib, it = i;
		}
		for(int j=0;j<n;j++)
			printf(j!=n-1 ? "%d " : "%d\n",it+1), it = take[it][j];
		printf("%d\n",ans);
	}
	return(0);
}
