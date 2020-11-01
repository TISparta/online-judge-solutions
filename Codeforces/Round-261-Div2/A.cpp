// Implementation
// 2
// 20-01-2016

#include <stdio.h>
#define abs(a) ( (a)<0 ? -(a) : (a) )


int main(){
        int x1,y1,x2,y2,x3,y3,x4,y4,ans= 1;
	scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
	if(x1 > 1000 || x2 > 1000 || x1 < -1000 || x2 < -1000) ans = -1;
	else if(y1 > 1000 || y2 > 1000 || y1 < -1000 || y2 < -1000) ans = -1;
	if(ans){
		if(x1 == x2 && y1 != y2){
			x3 = x1+ abs(y2-y1);
			x4 = x3;
			y3 = y1;
			y4 = y2;
			if(x3 > 1000 || x3 < -1000 ){
			x3 = x1 -(y2-y1);
			x4 = x3;
				if(x3 > 1000 || x3 < -1000)
				ans=-1;
			}
		}

		else if( y1 == y2 && x1 != x2){
			y3 = y1 + abs(x1-x2);
			y4 = y3;
			x3 = x1;
			x4 = x2;
			if(y3 > 1000 || y3 < -1000){
			y3 = y1 - abs(x1-x2);
			y4 = y3;
				if(y3 > 1000 || y3 < -1000)
				ans = -1;
			}
		}
		else{
			if(abs(x2-x1)==abs(y2-y1)){
				if(y2 > y1){
				x3 = x1;
				x4 = x2;
				y3 = y1 + abs(x2-x1);
				y4 = y2 - abs(x2-x1);
					if(y3 > 1000 || y4 > 1000 || y3 < -1000 || y4 < -1000)
					ans = -1;
				}
				if(y2 < y1){
				x3 = x1;
				x4 = x2;
				y3 = y1 - abs(x2-x1);
				y4 = y2 + abs(x2-x1);
					if(y3 > 1000 || y4 > 1000 || y3 < -1000 || y4 < -1000)
					ans = -1;
				}
			}
			else ans= -1;

		}

	}
	if(ans == -1) printf("-1\n");
	else printf("%d %d %d %d \n",x3,y3,x4,y4);
	return(0);
}
