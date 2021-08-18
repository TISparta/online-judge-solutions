// Tags: Greedy
// Difficulty: 1.3
// Priority: 3
// Date: 21-07-2016

#include <bits/stdc++.h>

using namespace std;

int n,top,a,b;
bool ok = true;

int main(){
	scanf("%d",&n);
	scanf("%d",&top);
	for(int i=0;i<n;i++){
		scanf("%d %d",&a,&b);
		if(a+b==7 || a==top || b==top || a==7-top || b==7-top)
			ok = false;
	}
	puts(ok ? "YES" : "NO");
	return(0);
}
