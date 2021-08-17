// Tags: Implementation
// Difficulty: 1.0
// Priority: 5
// Date: 06-02-2016

#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,k,ans=0;
	cin>>n>>k;
	int a[n+1];
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
		if(a[i]>=a[k] && a[i])
		ans++;
		else break;
	cout<<ans<<endl;
	return(0);
}
