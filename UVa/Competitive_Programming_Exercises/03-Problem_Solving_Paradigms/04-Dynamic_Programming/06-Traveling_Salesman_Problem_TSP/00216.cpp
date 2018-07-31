#include <bits/stdc++.h>

#define INF 10000000

using namespace std;

struct point{
	int x,y;
}p[10];

int tc,n;
vector<int>x,ans;
double min_cable,d[10][10],dd;
bool visited[10];

double dist(int x,int y,int xx,int yy){
	return sqrt((x-xx)*(x-xx)+(y-yy)*(y-yy))+16.00;
}

void backtrack(int pos, double req_cable){
	x.push_back(pos);
	if(x.size()==n){
		min_cable = req_cable;
		ans = x;
		return;
	}
	for(int it=0;it<n;it++)
		if(!visited[it]){
			dd = req_cable+dist(p[pos].x,p[pos].y,p[it].x,p[it].y);
			if(dd<min_cable){
				visited[it] = true;
				backtrack(it,dd);
				visited[it] = false;
				x.pop_back();
			}
		}
}

int main(){
	while(scanf("%d",&n),n){
		ans.clear(), min_cable = INF;
		for(int i=0;i<n;i++) scanf("%d %d",&p[i].x,&p[i].y);
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				d[i][j] = dist(p[i].x,p[i].y,p[j].x,p[j].y);
		for(int it=0;it<n;it++)
			memset(visited,false,sizeof visited), visited[it] = true, x.clear(), backtrack(it,0);
		printf("**********************************************************\n");
		printf("Network #%d\n",++tc);
		for(int i=0;i+1<n;i++)
			printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n",p[ans[i]].x,p[ans[i]].y,p[ans[i+1]].x,p[ans[i+1]].y,dist(p[ans[i]].x,p[ans[i]].y,p[ans[i+1]].x,p[ans[i+1]].y));
		printf("Number of feet of cable required is %.2lf.\n",min_cable);
	}
	return(0);
}
