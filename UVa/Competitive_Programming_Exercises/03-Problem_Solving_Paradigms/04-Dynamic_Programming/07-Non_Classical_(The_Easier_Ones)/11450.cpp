#include <bits/stdc++.h>

using namespace std;

int tc,M,C,price[25][25],score;
int memo[210][25];

int shop(int money,int g){
	if(money<0) return -1;
	if(g==C) return M-money;
	int &ans = memo[money][g];
	if(ans!=-1) return ans;
	for(int model=1;model<=price[g][0];model++)
		ans = max(ans,shop(money-price[g][model],g+1));
	return ans;
}

int main(){
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d",&M,&C);
		for(int i=0;i<C;i++){
			scanf("%d",&price[i][0]);
			for(int j=1;j<=price[i][0];j++) scanf("%d",&price[i][j]);
		}
		memset(memo,-1,sizeof memo);
		score = shop(M,0);
		if(score<0) puts("no solution");
		else printf("%d\n",score);
	}
	return(0);
}
